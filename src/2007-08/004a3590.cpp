// from server: 100% by colin
extern "C" unsigned long (__stdcall *inet_addr)(const char* cp);

struct S_func_004a3590 {
    unsigned int field;
    void f(const char* a1);
};

void S_func_004a3590::f(const char* a1)
{
    field = inet_addr(a1);
}
