// from server: 75% by atomic.potato
extern "C" void sub_007f47e4(void *);
extern "C" void sub_007f3c02(void *);

struct CWebToolbox {
    char pad0[248];
    void *m_field;
    void f(void *);
};

void CWebToolbox::f(void *arg)
{
    sub_007f47e4(arg);
    if (m_field)
        sub_007f3c02(m_field);
}
