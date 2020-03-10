// w ^dummy
#include <libyottadb.h>
#include <stdio.h>

int main()
{
	ydb_buffer_t	glo, val;
    char valuebuff[64];
	int	status;
    
    val.buf_addr = valuebuff;
    val.len_alloc = sizeof(valuebuff);
    
    YDB_LITERAL_TO_BUFFER("^dummy", &glo);
    status = ydb_get_s(&glo, 0, NULL, &val);
    val.buf_addr[val.len_used] = '\0';
    printf("%d %d %s\n", status, val.len_used, valuebuff);

	return 0;
}
