/* Generated by the protocol buffer compiler.  DO NOT EDIT! */

#ifndef PROTOBUF_C_query_5flanguage_2eproto__INCLUDED
#define PROTOBUF_C_query_5flanguage_2eproto__INCLUDED

#include <google/protobuf-c/protobuf-c.h>

PROTOBUF_C_BEGIN_DECLS


typedef struct _TableRef TableRef;
typedef struct _VarTermTuple VarTermTuple;
typedef struct _Term Term;
typedef struct _Term__Let Term__Let;
typedef struct _Term__Call Term__Call;
typedef struct _Term__If Term__If;
typedef struct _Term__GetByKey Term__GetByKey;
typedef struct _Term__Table Term__Table;
typedef struct _Builtin Builtin;
typedef struct _Builtin__Filter Builtin__Filter;
typedef struct _Builtin__Map Builtin__Map;
typedef struct _Builtin__ConcatMap Builtin__ConcatMap;
typedef struct _Builtin__OrderBy Builtin__OrderBy;
typedef struct _Builtin__GroupedMapReduce Builtin__GroupedMapReduce;
typedef struct _Builtin__Range Builtin__Range;
typedef struct _Reduction Reduction;
typedef struct _Mapping Mapping;
typedef struct _Predicate Predicate;
typedef struct _ReadQuery ReadQuery;
typedef struct _WriteQuery WriteQuery;
typedef struct _WriteQuery__Update WriteQuery__Update;
typedef struct _WriteQuery__Delete WriteQuery__Delete;
typedef struct _WriteQuery__Mutate WriteQuery__Mutate;
typedef struct _WriteQuery__Insert WriteQuery__Insert;
typedef struct _WriteQuery__ForEach WriteQuery__ForEach;
typedef struct _WriteQuery__PointUpdate WriteQuery__PointUpdate;
typedef struct _WriteQuery__PointDelete WriteQuery__PointDelete;
typedef struct _WriteQuery__PointMutate WriteQuery__PointMutate;
typedef struct _MetaQuery MetaQuery;
typedef struct _MetaQuery__CreateTable MetaQuery__CreateTable;
typedef struct _Query Query;
typedef struct _Response Response;
typedef struct _Response__Backtrace Response__Backtrace;


/* --- enums --- */

typedef enum _Term__TermType {
  TERM__TERM_TYPE__JSON_NULL = 0,
  TERM__TERM_TYPE__VAR = 1,
  TERM__TERM_TYPE__LET = 2,
  TERM__TERM_TYPE__CALL = 3,
  TERM__TERM_TYPE__IF = 4,
  TERM__TERM_TYPE__ERROR = 5,
  TERM__TERM_TYPE__NUMBER = 6,
  TERM__TERM_TYPE__STRING = 7,
  TERM__TERM_TYPE__JSON = 8,
  TERM__TERM_TYPE__BOOL = 9,
  TERM__TERM_TYPE__ARRAY = 10,
  TERM__TERM_TYPE__OBJECT = 11,
  TERM__TERM_TYPE__GETBYKEY = 12,
  TERM__TERM_TYPE__TABLE = 13,
  TERM__TERM_TYPE__JAVASCRIPT = 14,
  TERM__TERM_TYPE__IMPLICIT_VAR = 15
} Term__TermType;
typedef enum _Builtin__BuiltinType {
  BUILTIN__BUILTIN_TYPE__NOT = 1,
  BUILTIN__BUILTIN_TYPE__GETATTR = 2,
  BUILTIN__BUILTIN_TYPE__IMPLICIT_GETATTR = 3,
  BUILTIN__BUILTIN_TYPE__HASATTR = 4,
  BUILTIN__BUILTIN_TYPE__IMPLICIT_HASATTR = 5,
  BUILTIN__BUILTIN_TYPE__PICKATTRS = 6,
  BUILTIN__BUILTIN_TYPE__IMPLICIT_PICKATTRS = 7,
  BUILTIN__BUILTIN_TYPE__MAPMERGE = 8,
  BUILTIN__BUILTIN_TYPE__ARRAYAPPEND = 9,
  BUILTIN__BUILTIN_TYPE__SLICE = 11,
  BUILTIN__BUILTIN_TYPE__ADD = 14,
  BUILTIN__BUILTIN_TYPE__SUBTRACT = 15,
  BUILTIN__BUILTIN_TYPE__MULTIPLY = 16,
  BUILTIN__BUILTIN_TYPE__DIVIDE = 17,
  BUILTIN__BUILTIN_TYPE__MODULO = 18,
  BUILTIN__BUILTIN_TYPE__COMPARE = 19,
  BUILTIN__BUILTIN_TYPE__FILTER = 20,
  BUILTIN__BUILTIN_TYPE__MAP = 21,
  BUILTIN__BUILTIN_TYPE__CONCATMAP = 22,
  BUILTIN__BUILTIN_TYPE__ORDERBY = 23,
  BUILTIN__BUILTIN_TYPE__DISTINCT = 24,
  BUILTIN__BUILTIN_TYPE__LENGTH = 26,
  BUILTIN__BUILTIN_TYPE__UNION = 27,
  BUILTIN__BUILTIN_TYPE__NTH = 28,
  BUILTIN__BUILTIN_TYPE__STREAMTOARRAY = 29,
  BUILTIN__BUILTIN_TYPE__ARRAYTOSTREAM = 30,
  BUILTIN__BUILTIN_TYPE__REDUCE = 31,
  BUILTIN__BUILTIN_TYPE__GROUPEDMAPREDUCE = 32,
  BUILTIN__BUILTIN_TYPE__ANY = 35,
  BUILTIN__BUILTIN_TYPE__ALL = 36,
  BUILTIN__BUILTIN_TYPE__RANGE = 37,
  BUILTIN__BUILTIN_TYPE__IMPLICIT_WITHOUT = 38,
  BUILTIN__BUILTIN_TYPE__WITHOUT = 39
} Builtin__BuiltinType;
typedef enum _Builtin__Comparison {
  BUILTIN__COMPARISON__EQ = 1,
  BUILTIN__COMPARISON__NE = 2,
  BUILTIN__COMPARISON__LT = 3,
  BUILTIN__COMPARISON__LE = 4,
  BUILTIN__COMPARISON__GT = 5,
  BUILTIN__COMPARISON__GE = 6
} Builtin__Comparison;
typedef enum _WriteQuery__WriteQueryType {
  WRITE_QUERY__WRITE_QUERY_TYPE__UPDATE = 1,
  WRITE_QUERY__WRITE_QUERY_TYPE__DELETE = 2,
  WRITE_QUERY__WRITE_QUERY_TYPE__MUTATE = 3,
  WRITE_QUERY__WRITE_QUERY_TYPE__INSERT = 4,
  WRITE_QUERY__WRITE_QUERY_TYPE__FOREACH = 6,
  WRITE_QUERY__WRITE_QUERY_TYPE__POINTUPDATE = 7,
  WRITE_QUERY__WRITE_QUERY_TYPE__POINTDELETE = 8,
  WRITE_QUERY__WRITE_QUERY_TYPE__POINTMUTATE = 9
} WriteQuery__WriteQueryType;
typedef enum _MetaQuery__MetaQueryType {
  META_QUERY__META_QUERY_TYPE__CREATE_DB = 1,
  META_QUERY__META_QUERY_TYPE__DROP_DB = 2,
  META_QUERY__META_QUERY_TYPE__LIST_DBS = 3,
  META_QUERY__META_QUERY_TYPE__CREATE_TABLE = 4,
  META_QUERY__META_QUERY_TYPE__DROP_TABLE = 5,
  META_QUERY__META_QUERY_TYPE__LIST_TABLES = 6
} MetaQuery__MetaQueryType;
typedef enum _Query__QueryType {
  QUERY__QUERY_TYPE__READ = 1,
  QUERY__QUERY_TYPE__WRITE = 2,
  QUERY__QUERY_TYPE__CONTINUE = 3,
  QUERY__QUERY_TYPE__STOP = 4,
  QUERY__QUERY_TYPE__META = 5
} Query__QueryType;
typedef enum _Response__StatusCode {
  RESPONSE__STATUS_CODE__SUCCESS_EMPTY = 0,
  RESPONSE__STATUS_CODE__SUCCESS_JSON = 1,
  RESPONSE__STATUS_CODE__SUCCESS_PARTIAL = 2,
  RESPONSE__STATUS_CODE__SUCCESS_STREAM = 3,
  RESPONSE__STATUS_CODE__BROKEN_CLIENT = 101,
  RESPONSE__STATUS_CODE__BAD_QUERY = 102,
  RESPONSE__STATUS_CODE__RUNTIME_ERROR = 103
} Response__StatusCode;

/* --- messages --- */

struct  _TableRef
{
  ProtobufCMessage base;
  char *db_name;
  char *table_name;
  protobuf_c_boolean has_use_outdated;
  protobuf_c_boolean use_outdated;
};
#define TABLE_REF__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&table_ref__descriptor) \
    , NULL, NULL, 0,0 }


struct  _VarTermTuple
{
  ProtobufCMessage base;
  char *var;
  Term *term;
};
#define VAR_TERM_TUPLE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&var_term_tuple__descriptor) \
    , NULL, NULL }


struct  _Term__Let
{
  ProtobufCMessage base;
  size_t n_binds;
  VarTermTuple **binds;
  Term *expr;
};
#define TERM__LET__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&term__let__descriptor) \
    , 0,NULL, NULL }


struct  _Term__Call
{
  ProtobufCMessage base;
  Builtin *builtin;
  size_t n_args;
  Term **args;
};
#define TERM__CALL__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&term__call__descriptor) \
    , NULL, 0,NULL }


struct  _Term__If
{
  ProtobufCMessage base;
  Term *test;
  Term *true_branch;
  Term *false_branch;
};
#define TERM__IF__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&term__if__descriptor) \
    , NULL, NULL, NULL }


struct  _Term__GetByKey
{
  ProtobufCMessage base;
  TableRef *table_ref;
  char *attrname;
  Term *key;
};
#define TERM__GET_BY_KEY__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&term__get_by_key__descriptor) \
    , NULL, NULL, NULL }


struct  _Term__Table
{
  ProtobufCMessage base;
  TableRef *table_ref;
};
#define TERM__TABLE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&term__table__descriptor) \
    , NULL }


struct  _Term
{
  ProtobufCMessage base;
  Term__TermType type;
  char *var;
  Term__Let *let;
  Term__Call *call;
  Term__If *if_;
  char *error;
  protobuf_c_boolean has_number;
  double number;
  char *valuestring;
  char *jsonstring;
  protobuf_c_boolean has_valuebool;
  protobuf_c_boolean valuebool;
  size_t n_array;
  Term **array;
  size_t n_object;
  VarTermTuple **object;
  Term__GetByKey *get_by_key;
  Term__Table *table;
  char *javascript;
};
#define TERM__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&term__descriptor) \
    , (Term__TermType)0, NULL, NULL, NULL, NULL, NULL, 0,0, NULL, NULL, 0,0, 0,NULL, 0,NULL, NULL, NULL, NULL }


struct  _Builtin__Filter
{
  ProtobufCMessage base;
  Predicate *predicate;
};
#define BUILTIN__FILTER__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&builtin__filter__descriptor) \
    , NULL }


struct  _Builtin__Map
{
  ProtobufCMessage base;
  Mapping *mapping;
};
#define BUILTIN__MAP__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&builtin__map__descriptor) \
    , NULL }


struct  _Builtin__ConcatMap
{
  ProtobufCMessage base;
  Mapping *mapping;
};
#define BUILTIN__CONCAT_MAP__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&builtin__concat_map__descriptor) \
    , NULL }


struct  _Builtin__OrderBy
{
  ProtobufCMessage base;
  char *attr;
  protobuf_c_boolean has_ascending;
  protobuf_c_boolean ascending;
};
#define BUILTIN__ORDER_BY__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&builtin__order_by__descriptor) \
    , NULL, 0,1 }


struct  _Builtin__GroupedMapReduce
{
  ProtobufCMessage base;
  Mapping *group_mapping;
  Mapping *value_mapping;
  Reduction *reduction;
};
#define BUILTIN__GROUPED_MAP_REDUCE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&builtin__grouped_map_reduce__descriptor) \
    , NULL, NULL, NULL }


struct  _Builtin__Range
{
  ProtobufCMessage base;
  char *attrname;
  Term *lowerbound;
  Term *upperbound;
};
#define BUILTIN__RANGE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&builtin__range__descriptor) \
    , NULL, NULL, NULL }


struct  _Builtin
{
  ProtobufCMessage base;
  Builtin__BuiltinType type;
  char *attr;
  size_t n_attrs;
  char **attrs;
  protobuf_c_boolean has_comparison;
  Builtin__Comparison comparison;
  Builtin__Filter *filter;
  Builtin__Map *map;
  Builtin__ConcatMap *concat_map;
  size_t n_order_by;
  Builtin__OrderBy **order_by;
  Reduction *reduce;
  Builtin__GroupedMapReduce *grouped_map_reduce;
  Builtin__Range *range;
};
#define BUILTIN__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&builtin__descriptor) \
    , (Builtin__BuiltinType)0, NULL, 0,NULL, 0,(Builtin__Comparison)0, NULL, NULL, NULL, 0,NULL, NULL, NULL, NULL }


struct  _Reduction
{
  ProtobufCMessage base;
  // FIXME duplicate name base
  //Term *base;
  Term *fixed_base;
  char *var1;
  char *var2;
  Term *body;
};
#define REDUCTION__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&reduction__descriptor) \
    , NULL, NULL, NULL, NULL }


struct  _Mapping
{
  ProtobufCMessage base;
  char *arg;
  Term *body;
};
#define MAPPING__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&mapping__descriptor) \
    , NULL, NULL }


struct  _Predicate
{
  ProtobufCMessage base;
  char *arg;
  Term *body;
};
#define PREDICATE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&predicate__descriptor) \
    , NULL, NULL }


struct  _ReadQuery
{
  ProtobufCMessage base;
  Term *term;
  protobuf_c_boolean has_max_chunk_size;
  int64_t max_chunk_size;
  protobuf_c_boolean has_max_age;
  int64_t max_age;
};
#define READ_QUERY__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&read_query__descriptor) \
    , NULL, 0,0, 0,0 }


struct  _WriteQuery__Update
{
  ProtobufCMessage base;
  Term *view;
  Mapping *mapping;
};
#define WRITE_QUERY__UPDATE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&write_query__update__descriptor) \
    , NULL, NULL }


struct  _WriteQuery__Delete
{
  ProtobufCMessage base;
  Term *view;
};
#define WRITE_QUERY__DELETE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&write_query__delete__descriptor) \
    , NULL }


struct  _WriteQuery__Mutate
{
  ProtobufCMessage base;
  Term *view;
  Mapping *mapping;
};
#define WRITE_QUERY__MUTATE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&write_query__mutate__descriptor) \
    , NULL, NULL }


struct  _WriteQuery__Insert
{
  ProtobufCMessage base;
  TableRef *table_ref;
  size_t n_terms;
  Term **terms;
  protobuf_c_boolean has_overwrite;
  protobuf_c_boolean overwrite;
};
#define WRITE_QUERY__INSERT__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&write_query__insert__descriptor) \
    , NULL, 0,NULL, 0,0 }


struct  _WriteQuery__ForEach
{
  ProtobufCMessage base;
  Term *stream;
  char *var;
  size_t n_queries;
  WriteQuery **queries;
};
#define WRITE_QUERY__FOR_EACH__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&write_query__for_each__descriptor) \
    , NULL, NULL, 0,NULL }


struct  _WriteQuery__PointUpdate
{
  ProtobufCMessage base;
  TableRef *table_ref;
  char *attrname;
  Term *key;
  Mapping *mapping;
};
#define WRITE_QUERY__POINT_UPDATE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&write_query__point_update__descriptor) \
    , NULL, NULL, NULL, NULL }


struct  _WriteQuery__PointDelete
{
  ProtobufCMessage base;
  TableRef *table_ref;
  char *attrname;
  Term *key;
};
#define WRITE_QUERY__POINT_DELETE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&write_query__point_delete__descriptor) \
    , NULL, NULL, NULL }


struct  _WriteQuery__PointMutate
{
  ProtobufCMessage base;
  TableRef *table_ref;
  char *attrname;
  Term *key;
  Mapping *mapping;
};
#define WRITE_QUERY__POINT_MUTATE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&write_query__point_mutate__descriptor) \
    , NULL, NULL, NULL, NULL }


struct  _WriteQuery
{
  ProtobufCMessage base;
  WriteQuery__WriteQueryType type;
  protobuf_c_boolean has_atomic;
  protobuf_c_boolean atomic;
  WriteQuery__Update *update;
  WriteQuery__Delete *delete_;
  WriteQuery__Mutate *mutate;
  WriteQuery__Insert *insert;
  WriteQuery__ForEach *for_each;
  WriteQuery__PointUpdate *point_update;
  WriteQuery__PointDelete *point_delete;
  WriteQuery__PointMutate *point_mutate;
};
#define WRITE_QUERY__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&write_query__descriptor) \
    , (WriteQuery__WriteQueryType)0, 0,1, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL }


struct  _MetaQuery__CreateTable
{
  ProtobufCMessage base;
  char *datacenter;
  TableRef *table_ref;
  char *primary_key;
  protobuf_c_boolean has_cache_size;
  int64_t cache_size;
};
extern char meta_query__create_table__primary_key__default_value[];
#define META_QUERY__CREATE_TABLE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&meta_query__create_table__descriptor) \
    , NULL, NULL, meta_query__create_table__primary_key__default_value, 0,1073741824 }


struct  _MetaQuery
{
  ProtobufCMessage base;
  MetaQuery__MetaQueryType type;
  char *db_name;
  MetaQuery__CreateTable *create_table;
  TableRef *drop_table;
};
#define META_QUERY__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&meta_query__descriptor) \
    , (MetaQuery__MetaQueryType)0, NULL, NULL, NULL }


struct  _Query
{
  ProtobufCMessage base;
  Query__QueryType type;
  int64_t token;
  ReadQuery *read_query;
  WriteQuery *write_query;
  MetaQuery *meta_query;
};
#define QUERY__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&query__descriptor) \
    , (Query__QueryType)0, 0, NULL, NULL, NULL }


struct  _Response__Backtrace
{
  ProtobufCMessage base;
  size_t n_frame;
  char **frame;
};
#define RESPONSE__BACKTRACE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&response__backtrace__descriptor) \
    , 0,NULL }


struct  _Response
{
  ProtobufCMessage base;
  Response__StatusCode status_code;
  int64_t token;
  size_t n_response;
  char **response;
  char *error_message;
  Response__Backtrace *backtrace;
};
#define RESPONSE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&response__descriptor) \
    , (Response__StatusCode)0, 0, 0,NULL, NULL, NULL }


/* TableRef methods */
void   table_ref__init
                     (TableRef         *message);
size_t table_ref__get_packed_size
                     (const TableRef   *message);
size_t table_ref__pack
                     (const TableRef   *message,
                      uint8_t             *out);
size_t table_ref__pack_to_buffer
                     (const TableRef   *message,
                      ProtobufCBuffer     *buffer);
TableRef *
       table_ref__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   table_ref__free_unpacked
                     (TableRef *message,
                      ProtobufCAllocator *allocator);
/* VarTermTuple methods */
void   var_term_tuple__init
                     (VarTermTuple         *message);
size_t var_term_tuple__get_packed_size
                     (const VarTermTuple   *message);
size_t var_term_tuple__pack
                     (const VarTermTuple   *message,
                      uint8_t             *out);
size_t var_term_tuple__pack_to_buffer
                     (const VarTermTuple   *message,
                      ProtobufCBuffer     *buffer);
VarTermTuple *
       var_term_tuple__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   var_term_tuple__free_unpacked
                     (VarTermTuple *message,
                      ProtobufCAllocator *allocator);
/* Term__Let methods */
void   term__let__init
                     (Term__Let         *message);
/* Term__Call methods */
void   term__call__init
                     (Term__Call         *message);
/* Term__If methods */
void   term__if__init
                     (Term__If         *message);
/* Term__GetByKey methods */
void   term__get_by_key__init
                     (Term__GetByKey         *message);
/* Term__Table methods */
void   term__table__init
                     (Term__Table         *message);
/* Term methods */
void   term__init
                     (Term         *message);
size_t term__get_packed_size
                     (const Term   *message);
size_t term__pack
                     (const Term   *message,
                      uint8_t             *out);
size_t term__pack_to_buffer
                     (const Term   *message,
                      ProtobufCBuffer     *buffer);
Term *
       term__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   term__free_unpacked
                     (Term *message,
                      ProtobufCAllocator *allocator);
/* Builtin__Filter methods */
void   builtin__filter__init
                     (Builtin__Filter         *message);
/* Builtin__Map methods */
void   builtin__map__init
                     (Builtin__Map         *message);
/* Builtin__ConcatMap methods */
void   builtin__concat_map__init
                     (Builtin__ConcatMap         *message);
/* Builtin__OrderBy methods */
void   builtin__order_by__init
                     (Builtin__OrderBy         *message);
/* Builtin__GroupedMapReduce methods */
void   builtin__grouped_map_reduce__init
                     (Builtin__GroupedMapReduce         *message);
/* Builtin__Range methods */
void   builtin__range__init
                     (Builtin__Range         *message);
/* Builtin methods */
void   builtin__init
                     (Builtin         *message);
size_t builtin__get_packed_size
                     (const Builtin   *message);
size_t builtin__pack
                     (const Builtin   *message,
                      uint8_t             *out);
size_t builtin__pack_to_buffer
                     (const Builtin   *message,
                      ProtobufCBuffer     *buffer);
Builtin *
       builtin__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   builtin__free_unpacked
                     (Builtin *message,
                      ProtobufCAllocator *allocator);
/* Reduction methods */
void   reduction__init
                     (Reduction         *message);
size_t reduction__get_packed_size
                     (const Reduction   *message);
size_t reduction__pack
                     (const Reduction   *message,
                      uint8_t             *out);
size_t reduction__pack_to_buffer
                     (const Reduction   *message,
                      ProtobufCBuffer     *buffer);
Reduction *
       reduction__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   reduction__free_unpacked
                     (Reduction *message,
                      ProtobufCAllocator *allocator);
/* Mapping methods */
void   mapping__init
                     (Mapping         *message);
size_t mapping__get_packed_size
                     (const Mapping   *message);
size_t mapping__pack
                     (const Mapping   *message,
                      uint8_t             *out);
size_t mapping__pack_to_buffer
                     (const Mapping   *message,
                      ProtobufCBuffer     *buffer);
Mapping *
       mapping__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   mapping__free_unpacked
                     (Mapping *message,
                      ProtobufCAllocator *allocator);
/* Predicate methods */
void   predicate__init
                     (Predicate         *message);
size_t predicate__get_packed_size
                     (const Predicate   *message);
size_t predicate__pack
                     (const Predicate   *message,
                      uint8_t             *out);
size_t predicate__pack_to_buffer
                     (const Predicate   *message,
                      ProtobufCBuffer     *buffer);
Predicate *
       predicate__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   predicate__free_unpacked
                     (Predicate *message,
                      ProtobufCAllocator *allocator);
/* ReadQuery methods */
void   read_query__init
                     (ReadQuery         *message);
size_t read_query__get_packed_size
                     (const ReadQuery   *message);
size_t read_query__pack
                     (const ReadQuery   *message,
                      uint8_t             *out);
size_t read_query__pack_to_buffer
                     (const ReadQuery   *message,
                      ProtobufCBuffer     *buffer);
ReadQuery *
       read_query__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   read_query__free_unpacked
                     (ReadQuery *message,
                      ProtobufCAllocator *allocator);
/* WriteQuery__Update methods */
void   write_query__update__init
                     (WriteQuery__Update         *message);
/* WriteQuery__Delete methods */
void   write_query__delete__init
                     (WriteQuery__Delete         *message);
/* WriteQuery__Mutate methods */
void   write_query__mutate__init
                     (WriteQuery__Mutate         *message);
/* WriteQuery__Insert methods */
void   write_query__insert__init
                     (WriteQuery__Insert         *message);
/* WriteQuery__ForEach methods */
void   write_query__for_each__init
                     (WriteQuery__ForEach         *message);
/* WriteQuery__PointUpdate methods */
void   write_query__point_update__init
                     (WriteQuery__PointUpdate         *message);
/* WriteQuery__PointDelete methods */
void   write_query__point_delete__init
                     (WriteQuery__PointDelete         *message);
/* WriteQuery__PointMutate methods */
void   write_query__point_mutate__init
                     (WriteQuery__PointMutate         *message);
/* WriteQuery methods */
void   write_query__init
                     (WriteQuery         *message);
size_t write_query__get_packed_size
                     (const WriteQuery   *message);
size_t write_query__pack
                     (const WriteQuery   *message,
                      uint8_t             *out);
size_t write_query__pack_to_buffer
                     (const WriteQuery   *message,
                      ProtobufCBuffer     *buffer);
WriteQuery *
       write_query__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   write_query__free_unpacked
                     (WriteQuery *message,
                      ProtobufCAllocator *allocator);
/* MetaQuery__CreateTable methods */
void   meta_query__create_table__init
                     (MetaQuery__CreateTable         *message);
/* MetaQuery methods */
void   meta_query__init
                     (MetaQuery         *message);
size_t meta_query__get_packed_size
                     (const MetaQuery   *message);
size_t meta_query__pack
                     (const MetaQuery   *message,
                      uint8_t             *out);
size_t meta_query__pack_to_buffer
                     (const MetaQuery   *message,
                      ProtobufCBuffer     *buffer);
MetaQuery *
       meta_query__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   meta_query__free_unpacked
                     (MetaQuery *message,
                      ProtobufCAllocator *allocator);
/* Query methods */
void   query__init
                     (Query         *message);
size_t query__get_packed_size
                     (const Query   *message);
size_t query__pack
                     (const Query   *message,
                      uint8_t             *out);
size_t query__pack_to_buffer
                     (const Query   *message,
                      ProtobufCBuffer     *buffer);
Query *
       query__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   query__free_unpacked
                     (Query *message,
                      ProtobufCAllocator *allocator);
/* Response__Backtrace methods */
void   response__backtrace__init
                     (Response__Backtrace         *message);
/* Response methods */
void   response__init
                     (Response         *message);
size_t response__get_packed_size
                     (const Response   *message);
size_t response__pack
                     (const Response   *message,
                      uint8_t             *out);
size_t response__pack_to_buffer
                     (const Response   *message,
                      ProtobufCBuffer     *buffer);
Response *
       response__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   response__free_unpacked
                     (Response *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*TableRef_Closure)
                 (const TableRef *message,
                  void *closure_data);
typedef void (*VarTermTuple_Closure)
                 (const VarTermTuple *message,
                  void *closure_data);
typedef void (*Term__Let_Closure)
                 (const Term__Let *message,
                  void *closure_data);
typedef void (*Term__Call_Closure)
                 (const Term__Call *message,
                  void *closure_data);
typedef void (*Term__If_Closure)
                 (const Term__If *message,
                  void *closure_data);
typedef void (*Term__GetByKey_Closure)
                 (const Term__GetByKey *message,
                  void *closure_data);
typedef void (*Term__Table_Closure)
                 (const Term__Table *message,
                  void *closure_data);
typedef void (*Term_Closure)
                 (const Term *message,
                  void *closure_data);
typedef void (*Builtin__Filter_Closure)
                 (const Builtin__Filter *message,
                  void *closure_data);
typedef void (*Builtin__Map_Closure)
                 (const Builtin__Map *message,
                  void *closure_data);
typedef void (*Builtin__ConcatMap_Closure)
                 (const Builtin__ConcatMap *message,
                  void *closure_data);
typedef void (*Builtin__OrderBy_Closure)
                 (const Builtin__OrderBy *message,
                  void *closure_data);
typedef void (*Builtin__GroupedMapReduce_Closure)
                 (const Builtin__GroupedMapReduce *message,
                  void *closure_data);
typedef void (*Builtin__Range_Closure)
                 (const Builtin__Range *message,
                  void *closure_data);
typedef void (*Builtin_Closure)
                 (const Builtin *message,
                  void *closure_data);
typedef void (*Reduction_Closure)
                 (const Reduction *message,
                  void *closure_data);
typedef void (*Mapping_Closure)
                 (const Mapping *message,
                  void *closure_data);
typedef void (*Predicate_Closure)
                 (const Predicate *message,
                  void *closure_data);
typedef void (*ReadQuery_Closure)
                 (const ReadQuery *message,
                  void *closure_data);
typedef void (*WriteQuery__Update_Closure)
                 (const WriteQuery__Update *message,
                  void *closure_data);
typedef void (*WriteQuery__Delete_Closure)
                 (const WriteQuery__Delete *message,
                  void *closure_data);
typedef void (*WriteQuery__Mutate_Closure)
                 (const WriteQuery__Mutate *message,
                  void *closure_data);
typedef void (*WriteQuery__Insert_Closure)
                 (const WriteQuery__Insert *message,
                  void *closure_data);
typedef void (*WriteQuery__ForEach_Closure)
                 (const WriteQuery__ForEach *message,
                  void *closure_data);
typedef void (*WriteQuery__PointUpdate_Closure)
                 (const WriteQuery__PointUpdate *message,
                  void *closure_data);
typedef void (*WriteQuery__PointDelete_Closure)
                 (const WriteQuery__PointDelete *message,
                  void *closure_data);
typedef void (*WriteQuery__PointMutate_Closure)
                 (const WriteQuery__PointMutate *message,
                  void *closure_data);
typedef void (*WriteQuery_Closure)
                 (const WriteQuery *message,
                  void *closure_data);
typedef void (*MetaQuery__CreateTable_Closure)
                 (const MetaQuery__CreateTable *message,
                  void *closure_data);
typedef void (*MetaQuery_Closure)
                 (const MetaQuery *message,
                  void *closure_data);
typedef void (*Query_Closure)
                 (const Query *message,
                  void *closure_data);
typedef void (*Response__Backtrace_Closure)
                 (const Response__Backtrace *message,
                  void *closure_data);
typedef void (*Response_Closure)
                 (const Response *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCMessageDescriptor table_ref__descriptor;
extern const ProtobufCMessageDescriptor var_term_tuple__descriptor;
extern const ProtobufCMessageDescriptor term__descriptor;
extern const ProtobufCMessageDescriptor term__let__descriptor;
extern const ProtobufCMessageDescriptor term__call__descriptor;
extern const ProtobufCMessageDescriptor term__if__descriptor;
extern const ProtobufCMessageDescriptor term__get_by_key__descriptor;
extern const ProtobufCMessageDescriptor term__table__descriptor;
extern const ProtobufCEnumDescriptor    term__term_type__descriptor;
extern const ProtobufCMessageDescriptor builtin__descriptor;
extern const ProtobufCMessageDescriptor builtin__filter__descriptor;
extern const ProtobufCMessageDescriptor builtin__map__descriptor;
extern const ProtobufCMessageDescriptor builtin__concat_map__descriptor;
extern const ProtobufCMessageDescriptor builtin__order_by__descriptor;
extern const ProtobufCMessageDescriptor builtin__grouped_map_reduce__descriptor;
extern const ProtobufCMessageDescriptor builtin__range__descriptor;
extern const ProtobufCEnumDescriptor    builtin__builtin_type__descriptor;
extern const ProtobufCEnumDescriptor    builtin__comparison__descriptor;
extern const ProtobufCMessageDescriptor reduction__descriptor;
extern const ProtobufCMessageDescriptor mapping__descriptor;
extern const ProtobufCMessageDescriptor predicate__descriptor;
extern const ProtobufCMessageDescriptor read_query__descriptor;
extern const ProtobufCMessageDescriptor write_query__descriptor;
extern const ProtobufCMessageDescriptor write_query__update__descriptor;
extern const ProtobufCMessageDescriptor write_query__delete__descriptor;
extern const ProtobufCMessageDescriptor write_query__mutate__descriptor;
extern const ProtobufCMessageDescriptor write_query__insert__descriptor;
extern const ProtobufCMessageDescriptor write_query__for_each__descriptor;
extern const ProtobufCMessageDescriptor write_query__point_update__descriptor;
extern const ProtobufCMessageDescriptor write_query__point_delete__descriptor;
extern const ProtobufCMessageDescriptor write_query__point_mutate__descriptor;
extern const ProtobufCEnumDescriptor    write_query__write_query_type__descriptor;
extern const ProtobufCMessageDescriptor meta_query__descriptor;
extern const ProtobufCMessageDescriptor meta_query__create_table__descriptor;
extern const ProtobufCEnumDescriptor    meta_query__meta_query_type__descriptor;
extern const ProtobufCMessageDescriptor query__descriptor;
extern const ProtobufCEnumDescriptor    query__query_type__descriptor;
extern const ProtobufCMessageDescriptor response__descriptor;
extern const ProtobufCMessageDescriptor response__backtrace__descriptor;
extern const ProtobufCEnumDescriptor    response__status_code__descriptor;

PROTOBUF_C_END_DECLS


#endif  /* PROTOBUF_query_5flanguage_2eproto__INCLUDED */
