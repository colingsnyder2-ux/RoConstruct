// from server: 62% by atomic.potato
struct S_func_004a3630
{
    char pad0[36];
    int m_24;
    int m_28;
    int m_2c;
    S_func_004a3630 *f(void *);
};

extern "C" void func_00541450();
extern "C" void func_00540050(void *, void *);

S_func_004a3630 *S_func_004a3630::f(void *p)
{
    func_00541450();
    func_00540050(this, p);
    m_24 = ((int *)p)[0];
    m_28 = ((int *)p)[1];
    m_2c = ((int *)p)[2];
    return this;
}
