// w $increment(^dummy)
extern "C" {
#include <libyottadb.h>
}
#include <iostream>
#include <string>
using namespace std;

#define YDB_CPPSTR_TO_BUFFER(str, buf) buf.buf_addr = (char *) str.c_str(), buf.len_used = buf.len_alloc = str.length()
#define YDB_BUFFER_LEN 1024

int main()
{
	ydb_buffer_t glo, val = {YDB_BUFFER_LEN, YDB_BUFFER_LEN, new char[YDB_BUFFER_LEN]};
	string globalname = "^dummy";

	YDB_CPPSTR_TO_BUFFER(globalname, glo);
	if (!ydb_incr_s(&glo, 0, NULL, NULL, &val))
		cout <<  "result=" << string(val.buf_addr, val.len_used) << endl;

	return 0;
}
