#include "query_language.pb-c.h"

class RethinkDB {
 char *addr;
 unsigned short port;
 int timeout;
 // the socket
 int s;
 // version sent ?
 int version_sent;
 // buffer for the query
 char *query_buf;
 // buffer for the response
 void *response_buf;
 // token
 int64_t token;

public:

 RethinkDB (char *, unsigned short, int);

 int send(const void *, size_t);
 int connect();
 int send_version();
 int check();
 int send_protobuf(size_t);
 int send_query(Query *);
 int recv(void *, size_t);
 int32_t response_size();
 Response *response();
 int response_check(int);
 char **response_list(unsigned int *);
 char *response_json();
 int create_db(char *);
 int create_table(char *, char *, char *, char *, int);
 char **list_db(unsigned int *);
 char **table(char *, char *, int, unsigned int *);
 char *get(char *, char *, char *, char *, int);
 char **filter(char *, char *, char *, unsigned int *);
 char *insert(char *, char *, char **, unsigned int, int);

};
