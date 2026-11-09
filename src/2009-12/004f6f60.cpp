// from server: 68% by atomic.potato
extern "C" void G1_func_004020a0(void *, void *);
extern "C" void G1_func_00636d80(void *, void *);

struct S
{
    void f(void *);
};

void S::f(void *p)
{
    void *v = *(void **)p;
    *(void **)((char *)this + 164) = v;
    G1_func_004020a0((char *)this + 168, (char *)p + 4);
    G1_func_00636d80(v, this);
}
