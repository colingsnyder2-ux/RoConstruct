// from server: 84% by atomic.potato
extern "C" void __stdcall destroy_string(void *);
extern "C" void __stdcall call_global(void *);

struct S
{
    int f(int);
};

int S::f(int a)
{
    *(int *)this = 0xa9c7bc;
    call_global((char *)this + 0xc020);
    if ((a & 1) != 0)
        destroy_string(this);
    return (int)this;
}
