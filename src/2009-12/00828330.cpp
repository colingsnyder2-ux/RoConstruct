// from server: 96% by atomic.potato
struct S {
    int reserved[11];
    int *p;
    void f();
};

void S::f()
{
    if (p)
        ((void (__thiscall *)(int *))(*(void (**)(int *))(*p + 0x68)))(p);
    p = 0;
}
