// from server: 100% by atomic.potato
struct S_func_00792df0
{
    int m_pad;
    int* m_begin;
    int* m_end;
    int m_pad2[2];
    int m_value;
    void f();
};

void S_func_00792df0::f()
{
    int* p = m_begin;
    while (p != m_end)
    {
        *p = 0;
        ++p;
    }
    m_value = 0;
}
