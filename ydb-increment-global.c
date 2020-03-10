// w $increment(^dummy)
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
    status = ydb_incr_s(&glo, 0, NULL, NULL, &val);
    val.buf_addr[val.len_used] = '\0';
    printf("status=%d\nvalue=%s\n", status, valuebuff);

	return 0;
}
