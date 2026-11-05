// from server: 83% by atomic.potato
struct S
{
    void f(int);
};

void S::f(int value)
{
    *(int *)((char *)this + 0xb4) = *(int *)value;
    value += 4;
    ((void (__thiscall *)(S *, int))0x402090)((S *)((char *)this + 0xb8), value);
}
