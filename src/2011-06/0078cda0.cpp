// from server: 74% by atomic.potato
extern "C" void __cdecl RobloxCall(int);

struct S
{
    void f();
    void *a;
    void *b;
};

void S::f()
{
    void **p = (void **)((char *)this - 0x4c);
    void **v = (void **)p[0];
    ((void (__thiscall *)(void *))v[0x30 / 4])(p);
    void *q = b;
    if (q)
        RobloxCall(0);
}
