// from server: 100% by tester
struct Sub_639cc0 {
    char pad[0x38];
    int m_val;
};

struct S_639cc0 {
    char pad0[0xa0];
    int m_a0;
    char pad1[0x158 - 0xa0 - 4];
    Sub_639cc0* m_p158;
    int f();
};

int S_639cc0::f()
{
    int r = m_a0;
    if (r == -1) {
        Sub_639cc0* p = m_p158;
        if (p != 0) {
            r = p->m_val;
        }
    }
    return r;
}
