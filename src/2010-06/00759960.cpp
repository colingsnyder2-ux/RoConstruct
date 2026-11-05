// from server: 96% by atomic.potato
extern "C" void __cdecl Function_00759820(void *, int);
extern "C" void __cdecl Function_007A799A(void *);

struct S {
    int unused;
    void *value;
    void f();
};

void S::f()
{
    void *p = value;
    if (p != 0) {
        Function_00759820(p, *(int *)((char *)p + 0x14));
        Function_007A799A(p);
    }
}
