// from server: 58% by atomic.potato
struct S
{
    S *f();
};

extern "C" void __cdecl G1_func_0042c3f0(void *, void *);
extern int G1_data_00e163b0;

S *S::f()
{
    S *p = this;
    S *q = p;
    G1_func_0042c3f0(&q, &p);
    *(int *)p = 0x00b434cc;
    return p;
}
