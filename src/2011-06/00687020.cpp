// from server: 91% by atomic.potato
struct S_func_00687020
{
    char pad[40];
    int m_base;
    int m_index;
    void f(void *p);
};

extern "C" void __fastcall sub_004c0590(void *, void *);

void S_func_00687020::f(void *p)
{
    char *q = p ? (char *)p - 28 : 0;
    int v = *(int *)(q + 324);
    v = *(int *)((char *)v + m_index) + m_base;
    sub_004c0590((char *)(q + 324) + v, 0);
}
