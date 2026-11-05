// from server: 65% by atomic.potato
typedef unsigned int (__thiscall *Callback)(void *, void *);

extern "C" void __stdcall G1_func_005a9c80(void *, void *);

struct S
{
    void f(void *);
};

void S::f(void *arg)
{
    void *p = *(void **)((char *)this + 0x1c);
    void *a = 0;
    Callback cb = *(Callback *)((char *)*(void **)p + 0xc);
    cb(p, &a);
    G1_func_005a9c80(arg, &a);
}
