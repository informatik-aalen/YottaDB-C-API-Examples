// s ind="" f  s ind=$O(^dummy(ind)) q:ind=""  w ind,!
#include <libyottadb.h>
#include <stdio.h>
#include <string.h>

int main()
{
    ydb_buffer_t glo, val, ind[1];
    char valuebuff[64], index[64] = "";
    int	status;
    
    val.buf_addr = valuebuff;
    val.len_alloc = sizeof(valuebuff);
    YDB_LITERAL_TO_BUFFER("^dummy", &glo);
	
	while(1) {
		ind[0].buf_addr = index, ind[0].len_used =strlen(index), ind[0].len_alloc = sizeof(index);
		status = ydb_subscript_next_s(&glo, 1, ind, &val);
		if (status)
			break;
		val.buf_addr[val.len_used] = '\0';
		printf("%s\n", valuebuff);
		strcpy(index, val.buf_addr);
	} while (!status);
    return 0;
}
