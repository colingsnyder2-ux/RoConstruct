// from server: 78% by atomic.potato
extern "C" int G1_func_007b7360(void *, void *);
extern "C" void G1_func_006a51d0();

struct S
{
    int f(void *);
};

int S::f(void *p)
{
    int r = G1_func_007b7360((char *)this + 0x1e0, &p);
    if (*(void **)((char *)this + 0x200) != 0 && r == 0)
        G1_func_006a51d0();
    return 0;
}
