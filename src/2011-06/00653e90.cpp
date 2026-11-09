// from server: 83% by atomic.potato
typedef char* String;
extern "C" String basic_string_assign(String, const char*);

void f_00653e90()
{
    basic_string_assign((String)0x00ccd508, (const char*)0x00a9a72c);
}
