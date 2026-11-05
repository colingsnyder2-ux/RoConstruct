// from server: 80% by atomic.potato
extern "C" void G1_func_007d79a0(void *, int);

struct S {
    int __stdcall f(int);
};

int __stdcall S::f(int value)
{
    G1_func_007d79a0(this, value);
    *(int *)this = 0x9ef570;
    *((int *)this + 1) = 0x9ef568;
    return (int)this;
}
