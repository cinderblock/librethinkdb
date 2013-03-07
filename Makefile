all:
	$(CXX) -g -Wall -shared -fPIC -o librethinkdb.so librethinkdb.cpp query_language.pb-c.c -lprotobuf-c
