#include "librethinkdb.h"

/*
	send the specified amount of datas to the socket
 */
int RethinkDB::send(void *buf, size_t len) {
 size_t remains = len;
 void *ptr = buf;
 while (remains) {
  ssize_t rlen = write(this->s, ptr, remains);
  if (rlen <= 0) {
   return -1;
  }
  ptr += rlen;
  remains -= rlen;
 }
 return 0;
}

/*
	connect to a server
 */
int RethinkDB::connect() {

 if (this->s >= 0) return 0;

 struct sockaddr_in sin;
 memset(&sin, 0, sizeof (sin));

 this->s = socket(AF_INET, SOCK_STREAM, 0);
 if (this->s < 0) {
  return -1;
 }

 sin.sin_family = AF_INET;
 sin.sin_addr.s_addr = inet_addr(this->addr);
 sin.sin_port = htons(this->port);

 if (connect(this->s, (struct sockaddr *) &sin, sizeof (sin))) {
  close(this->s);
  this->s = -1;
  return -1;
 }

 return 0;

}

/*
	send the version string
 */
int RethinkDB::send_version() {
 if (this->version_sent) return 0;
 int ret = send("\x35\xba\x61\xaf", 4);
 if (ret == 0) {
  this->version_sent = 1;
  return 0;
 }
 return -1;
}

/*
	check if the connection is valid
 */
int RethinkDB::check() {
 if (connect()) {
  return -1;
 }
 return send_version();
}

/*
	send a protobuf packet (prefixed with the size)
 */
int RethinkDB::send_protobuf(size_t len) {
 char *ptr = this->query_buf;
 ptr[0] = (char) (len & 0xff);
 ptr[1] = (char) (len >> 8) & 0xff;
 ptr[2] = (char) (len >> 16) & 0xff;
 ptr[3] = (char) (len >> 24) & 0xff;
 return send(this->query_buf, len + 4);
}

/*
	send a query
 */
int RethinkDB::send_query(Query *q) {
 size_t len = query__get_packed_size(q);
 this->query_buf = malloc(len + 4);
 query__pack(q, this->query_buf + 4);
 int ret = protobuf(len);
 free(this->query_buf);
 this->query_buf = NULL;
 return ret;
}

/*
	receive the specified amount of datas
 */
int RethinkDB::recv(void *buf, size_t len) {
 size_t remains = len;
 void *ptr = buf;
 while (remains) {
  ssize_t rlen = read(this->s, ptr, remains);
  if (rlen <= 0) {
   return -1;
  }
  ptr += rlen;
  remains -= rlen;
 }
 return 0;
}

/*
	get the size of a response
 */
int32_t RethinkDB::response_size() {
 int32_t len = 0;
 if (recv(&len, 4)) {
  return 0;
 }
 char *ptr = (char *) &len;
 ptr[0] = (char) (len & 0xff);
 ptr[1] = (char) (len >> 8) & 0xff;
 ptr[2] = (char) (len >> 16) & 0xff;
 ptr[3] = (char) (len >> 24) & 0xff;
 return len;
}

/*
	parse a response
 */
Response *RethinkDB::response() {
 int32_t len = response_size();
 if (len == 0) return NULL;
 this->response_buf = malloc(len);
 if (recv(this->response_buf, len)) {
  free(this->response_buf);
  this->response_buf = NULL;
  return NULL;
 }
 return response__unpack(NULL, len, this->response_buf);
}

/*
	check for a specific response code
 */
int RethinkDB::response_check(int val) {
 Response *r = response();
 int ret = r->status_code;
 free(this->response_buf);
 this->response_buf = NULL;

 if (ret == val) {
  return 0;
 }
 return -1;
}

/*
	get the list of response strings
 */
char **RethinkDB::response_list(unsigned int *len) {
 Response *r = response();
 if (r->status_code == RESPONSE__STATUS_CODE__SUCCESS_STREAM) {
  *len = r->n_response;
  return r->response;
 }
 return NULL;
}

/*
	get a JSON response
 */
char *RethinkDB::response_json() {
 Response *r = response();
 if (r->status_code == RESPONSE__STATUS_CODE__SUCCESS_JSON) {
  if (r->n_response > 0) {
   return r->response[0];
  }
 }
 return NULL;
}

/*
	create a db
 */
int RethinkDB::create_db(char *dbname) {
 if (check()) return -1;

 Query q = QUERY__INIT;
 MetaQuery mq = META_QUERY__INIT;
 q.type = QUERY__QUERY_TYPE__META;
 q.token = this->token;
 q.meta_query = &mq;
 mq.type = META_QUERY__META_QUERY_TYPE__CREATE_DB;
 mq.db_name = dbname;

 if (send_query(&q)) {
  return -1;
 }

 return response_check(RESPONSE__STATUS_CODE__SUCCESS_EMPTY);
}

/*
	create a table
 */
int RethinkDB::create_table(char *dbname, char *tablename, char *datacenter, char *pkey, int use_outdated) {
 if (check()) return -1;

 Query q = QUERY__INIT;
 MetaQuery mq = META_QUERY__INIT;
 MetaQuery__CreateTable ct = META_QUERY__CREATE_TABLE__INIT;
 TableRef tr = TABLE_REF__INIT;

 q.type = QUERY__QUERY_TYPE__META;
 q.token = this->token;
 q.meta_query = &mq;

 mq.type = META_QUERY__META_QUERY_TYPE__CREATE_TABLE;
 mq.create_table = &ct;

 ct.datacenter = datacenter;
 ct.primary_key = pkey;
 ct.table_ref = &tr;

 tr.db_name = dbname;
 tr.table_name = tablename;
 tr.use_outdated = use_outdated;

 if (send_query(&q)) {
  return -1;
 }

 return response_check(RESPONSE__STATUS_CODE__SUCCESS_EMPTY);
}

/*
	list dbs
 */
char **RethinkDB::list_db(unsigned int *len) {

 if (check()) return NULL;

 Query q = QUERY__INIT;
 MetaQuery mq = META_QUERY__INIT;
 q.type = QUERY__QUERY_TYPE__META;
 q.token = this->token;
 q.meta_query = &mq;
 mq.type = META_QUERY__META_QUERY_TYPE__LIST_DBS;

 if (send_query(&q)) {
  return NULL;
 }

 return response_list(len);

}

/*
	r.table('table')
 */
char **RethinkDB::table(char *dbname, char *tablename, int use_outdated, unsigned int *len) {
 if (check()) return NULL;

 Query q = QUERY__INIT;
 ReadQuery rq = READ_QUERY__INIT;
 Term t = TERM__INIT;
 Term__Table tb = TERM__TABLE__INIT;
 TableRef tr = TABLE_REF__INIT;

 q.type = QUERY__QUERY_TYPE__READ;
 q.token = this->token;
 q.read_query = &rq;

 rq.term = &t;

 t.type = TERM__TERM_TYPE__TABLE;
 t.table = &tb;

 tb.table_ref = &tr;

 tr.db_name = dbname;
 tr.table_name = tablename;
 tr.use_outdated = use_outdated;


 if (send_query(&q)) {
  return NULL;
 }

 return response_list(len);
}

/*
	init a rethinkdb connection
 */
RethinkDB::RethinkDB(char *address, unsigned short port, int timeout) {
 this->s = -1;
 this->addr = address;
 this->port = port;
 this->timeout = timeout;
}

/*
	r.table('table').get('id')
 */
char *RethinkDB::get(char *dbname, char *tablename, char *pk, char *attr, int use_outdated) {

 if (check()) return NULL;

 Query q = QUERY__INIT;
 ReadQuery rq = READ_QUERY__INIT;
 Term t = TERM__INIT;
 Term tk = TERM__INIT;
 Term__GetByKey gbk = TERM__GET_BY_KEY__INIT;
 TableRef tr = TABLE_REF__INIT;

 q.type = QUERY__QUERY_TYPE__READ;
 q.token = this->token;
 q.read_query = &rq;

 rq.term = &t;

 t.type = TERM__TERM_TYPE__GETBYKEY;
 t.get_by_key = &gbk;

 gbk.table_ref = &tr;
 if (!attr) {
  gbk.attrname = "id";
 } else {
  gbk.attrname = attr;
 }
 gbk.key = &tk;

 tr.db_name = dbname;
 tr.table_name = tablename;
 tr.use_outdated = use_outdated;

 tk.type = TERM__TERM_TYPE__STRING;
 tk.valuestring = pk;


 if (send_query(&q)) {
  return NULL;
 }

 return response_json();
}

/*
FIXME
	r.table('table').filter(...)
 */
char **RethinkDB::filter(char *dbname, char *tablename, char *filter, unsigned int *len) {

 if (check()) return NULL;

 Query q = QUERY__INIT;
 ReadQuery rq = READ_QUERY__INIT;
 Term t = TERM__INIT;
 //Term j = TERM__INIT;
 Term__Call tc = TERM__CALL__INIT;
 Builtin b = BUILTIN__INIT;
 Builtin__Filter f = BUILTIN__FILTER__INIT;
 Predicate p = PREDICATE__INIT;

 q.type = QUERY__QUERY_TYPE__READ;
 q.token = this->token;
 q.read_query = &rq;

 rq.term = &t;

 t.type = TERM__TERM_TYPE__CALL;
 t.call = &tc;

 tc.builtin = &b;

 b.type = BUILTIN__BUILTIN_TYPE__FILTER;
 b.filter = &f;

 f.predicate = &p;
 //p. = &j;

 //j.type = TERM__TERM_TYPE__JSON;
 //j.jsonstring = filter;

 if (send_query(&q)) {
  return NULL;
 }

 return response_list(len);
}

/*
	r.table('table').insert([{...}])

 */
char *RethinkDB::insert(char *dbname, char *tablename, char **json, unsigned int json_n, int upsert) {

 char *json_r = NULL;

 Query q = QUERY__INIT;
 WriteQuery wq = WRITE_QUERY__INIT;
 WriteQuery__Insert in = WRITE_QUERY__INSERT__INIT;
 TableRef tr = TABLE_REF__INIT;


 q.type = QUERY__QUERY_TYPE__WRITE;
 q.token = this->token;
 q.write_query = &wq;

 wq.type = WRITE_QUERY__WRITE_QUERY_TYPE__INSERT;
 wq.insert = &in;

 tr.db_name = dbname;
 tr.table_name = tablename;

 in.table_ref = &tr;
 in.n_terms = json_n;
 in.terms = malloc(sizeof (Term *) * json_n);
 unsigned int i;
 for (i = 0; i < json_n; i++) {
  in.terms[i] = malloc(sizeof (Term));
  term__init(in.terms[i]);
  in.terms[i]->type = TERM__TERM_TYPE__JSON;
  in.terms[i]->jsonstring = json[i];
 }
 in.overwrite = upsert;

 if (s!end_query(this, &q))
  json_r = response_json();

 for (i = 0; i < json_n; i++) {
  free(in.terms[i]);
 }
 free(in.terms);

 return json_r;
}
