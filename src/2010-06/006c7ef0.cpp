// from server: 59% by atomic.potato
extern "C" void sub_006c7d30(void *, float, int);

struct S_func_006c7ef0 {
    char pad0[8];
    void *m_base;
    void *m_owner;
    void *f(float value, int arg);
};

void *S_func_006c7ef0::f(float value, int arg)
{
    void *p = m_base;
    if (p)
        p = (char *)p + 28;
    sub_006c7d30(m_owner, value, arg);
    return p;
}
