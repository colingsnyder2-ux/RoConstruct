// from server: 82% by atomic.potato
struct S
{
    int f(void *);
};

extern "C" void G1_func_004020a0(void *, void *);
extern "C" void __cdecl G1_func_00636d80(void *, void *);

int S::f(void *p)
{
    int v = *(int *)p;
    *(int *)((char *)this + 0x9c) = v;
    G1_func_004020a0((char *)this + 0xa0, (char *)p + 4);
    G1_func_00636d80(*(void **)p, this);
    return 0;
}
