// from server: 78% by atomic.potato
typedef int __stdcall T_func_0080b1d8(void *, unsigned int, unsigned int, const char *);

extern T_func_0080b1d8 func_0080b1d8;

struct S
{
    int f();
};

int S::f()
{
    return func_0080b1d8((char *)this + 0x108, 0x10, 2, "seSW");
}
