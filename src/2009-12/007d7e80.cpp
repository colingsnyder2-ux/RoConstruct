// from server: 82% by atomic.potato
struct S
{
    int __stdcall f(int value);
};

extern "C" void G1_func_007de620(S *, int, int);

int __stdcall S::f(int value)
{
    G1_func_007de620(this, value, value);
    *(int *)this = 0x9ef728;
    *(int *)((char *)this + 4) = 0x9ef720;
    return (int)this;
}
