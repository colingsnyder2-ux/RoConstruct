// from server: 76% by atomic.potato
struct S
{
    int f();
};

extern "C" int __stdcall G1_func_004df530(void *, const void *);
extern "C" int __stdcall G1_func_006d0860(void *, const void *);

int S::f()
{
    if (G1_func_004df530(this, (const void *)0x00c2f9b8))
        if (G1_func_006d0860((char *)this + 0x10, (const void *)0x00cb963c))
            return 1;
    return 0;
}
