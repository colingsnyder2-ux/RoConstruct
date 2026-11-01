// from server: 100% by colin
struct P_func_004a67f0 {
    char pad[0x138];
    int value;
};

struct S_func_004a67f0 {
    char pad[0x1d8c];
    P_func_004a67f0* m_p;
    int f();
};

int S_func_004a67f0::f()
{
    if (m_p)
        return m_p->value;
    return 0;
}
