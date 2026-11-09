// from server: 100% by atomic.potato
struct S
{
    void f();
    void *v0;
    void *v1;
    void *v2;
    void *v3;
    void *v4;
    void *v5;
    void *v6;
    void *v7;
};

extern "C" void __cdecl target();

void S::f()
{
    v0 = (void *)0xbed76c;
    v1 = (void *)0xbed764;
    v6 = (void *)0xbed758;
    v7 = (void *)0xbed74c;
    target();
}
