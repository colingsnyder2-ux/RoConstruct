// from server: 77% by atomic.potato
extern "C" void __stdcall G1_func_00785a00(int);

struct S
{
    S *f(int);
};

S *S::f(int value)
{
    G1_func_00785a00(value);
    *(int *)this = 0x9d3ec4;
    *((int *)this + 1) = 0x9d3eac;
    *((int *)this + 7) = 0;
    *((int *)this + 8) = 0;
    return this;
}
