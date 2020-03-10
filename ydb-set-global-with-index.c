// SET ^dummy(1,2,"hallo")="Hallo Winfried!"

#include <libyottadb.h>
#include <stdio.h>

int main()
{
    ydb_buffer_t glo, val, ind[3];
    int	status;
    
    YDB_LITERAL_TO_BUFFER("^dummy", &glo);
    YDB_LITERAL_TO_BUFFER("Hallo Winfried!", &val);
    YDB_LITERAL_TO_BUFFER("1", ind);
    YDB_LITERAL_TO_BUFFER("2", ind+1);
    YDB_LITERAL_TO_BUFFER("hallo", ind+2);
    
    status = ydb_set_s(&glo, 3, ind, &val);
	printf("status=%d\n", status);
    return 0;
}
