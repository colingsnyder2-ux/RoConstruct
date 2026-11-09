// from server: 85% by atomic.potato
typedef unsigned long DWORD;

extern "C" void __stdcall sub_0052dba0(void *, const char *, DWORD);

struct S_func_0051f5a0 {
    void f(const char *, DWORD);
};

void S_func_0051f5a0::f(const char *a, DWORD b)
{
    if (a != 0 && *a != 0 && b != 0)
        sub_0052dba0((char *)this + 0x86c, a, b);
}
