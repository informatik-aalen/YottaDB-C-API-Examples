ydb=$(shell pkg-config --variable=prefix yottadb)
options=-I$(ydb) -L$(ydb) -lyottadb -Wall

all: ydb-set-global ydb-set-global-with-index ydb-increment-global ydb-get-global ydb-next-index ydb-cplusplus

ydb-set-global: ydb-set-global.c
	gcc ydb-set-global.c $(options) -o ydb-set-global

ydb-set-global-with-index: ydb-set-global-with-index.c
	gcc ydb-set-global-with-index.c $(options) -o ydb-set-global-with-index

ydb-increment-global: ydb-increment-global.c
	gcc ydb-increment-global.c $(options) -o ydb-increment-global

ydb-get-global: ydb-get-global.c
	gcc ydb-get-global.c $(options) -o ydb-get-global

ydb-next-index: ydb-next-index.c
	gcc ydb-next-index.c $(options) -o ydb-next-index

ydb-cplusplus: ydb-cplusplus.cpp
	g++ ydb-cplusplus.cpp $(options) -o ydb-cplusplus

clean:
	rm ydb-set-global ydb-set-global-with-index ydb-increment-global ydb-get-global ydb-next-index ydb-cplusplus
