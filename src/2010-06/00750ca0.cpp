// from server: 79% by atomic.potato
struct S_func_00750ca0 {
    char pad0[4];
    int m_field4;
    char pad8[0x28];
    char* m_field30;
    char* m_field34;
    void f();
};

void S_func_00750ca0::f()
{
    char* p = m_field30;
    if (p == 0 || p[4] == 0) {
        if (m_field4 != 0) {
            ((S_func_00750ca0*)m_field4)->f();
        } else {
            char* q = m_field34;
            if (q != 0)
                q[8] = 1;
        }
        if (m_field30 != 0)
            m_field30[4] = 1;
    }
}
