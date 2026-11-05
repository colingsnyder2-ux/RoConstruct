// from server: 70% by atomic.potato
extern "C" int __cdecl G1_func_004d78a0(void *, int);

struct S
{
    int f(int);
};

int S::f(int value)
{
    int *p = *(int **)((char *)this - 0x1c4);
    typedef int (__cdecl *Fn)(void *);
    Fn fn = *(Fn *)((char *)p + 0x148);
    fn((char *)this - 0x1c4);
    G1_func_004d78a0((void *)value, value);
    return value;
}
