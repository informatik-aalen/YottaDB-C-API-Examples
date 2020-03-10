// SET ^dummy="Hallo Winfried!"

#include <libyottadb.h>
#include <stdio.h>

int main()
{
	ydb_buffer_t	glo, val;
	int	status;
    
    YDB_LITERAL_TO_BUFFER("^dummy", &glo);
    YDB_LITERAL_TO_BUFFER("Hallo Winfried!", &val);
    status = ydb_set_s(&glo, 0, NULL, &val);
	printf("status=%d\n", status);
	return 0;
}
