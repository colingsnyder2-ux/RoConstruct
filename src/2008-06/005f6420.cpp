// from server: 100% by atomic.potato
struct S
{
    int f(S *p);
};

extern "C" void __stdcall callee(S *p);

int S::f(S *p)
{
    callee(p);
    *(int *)this = 0x840b0c;
    *(int *)((char *)this + 0x28) = *(int *)((char *)p + 0x28);
    *(int *)((char *)this + 0x2c) = *(int *)((char *)p + 0x2c);
    return (int)this;
}
