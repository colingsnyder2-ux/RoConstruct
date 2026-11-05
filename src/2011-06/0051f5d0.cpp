// from server: 80% by atomic.potato
extern "C" void __stdcall sub_0052dba0(void *, const char *, int);

struct S_func_0051f5d0 {
    char pad0[0x86c];
    void f(const char *, int);
};

void S_func_0051f5d0::f(const char *a, int b)
{
    if (a != 0 && *a != 0 && b != 0)
        sub_0052dba0((char *)this + 0x86c, a, 1);
}
