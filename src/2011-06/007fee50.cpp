// from server: 100% by atomic.potato
typedef unsigned long DWORD;

extern "C" DWORD __cdecl get_file_attributes(const char *);

struct S_func_007fee50
{
    DWORD m_value;
    void f();
};

void S_func_007fee50::f()
{
    get_file_attributes((const char *)(m_value + 4));
}
