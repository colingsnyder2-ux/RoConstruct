// from server: 68% by atomic.potato
struct S_func_0092b620
{
    char pad0[2120];
    int m_x;
    int f();
};

int S_func_0092b620::f()
{
    return m_x;
}

struct RbxPartBinding
{
    char pad0[28];
    int *m_data;
    char pad1[48];
    char m_flag;
    int f();
};

int RbxPartBinding::f()
{
    int *p = m_data;
    m_flag = 1;
    S_func_0092b620 *q = *(S_func_0092b620 **)((char *)p + 0x170);
    q = *(S_func_0092b620 **)((char *)q + 0x4880);
    return q->f();
}
