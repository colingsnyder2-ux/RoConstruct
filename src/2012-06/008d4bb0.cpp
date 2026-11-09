// from server: 95% by atomic.potato
extern "C" void __cdecl call_414da0(const char *);

struct S_008d4bb0 {
    char pad0[396];
    int m_value;
    void f(int value);
};

void S_008d4bb0::f(int value)
{
    if (m_value != value) {
        m_value = value;
        call_414da0("XSUV3");
    }
}
