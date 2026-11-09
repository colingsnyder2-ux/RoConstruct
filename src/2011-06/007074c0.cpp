// from server: 87% by atomic.potato
extern "C" void sub_00411f60(void *, const char *);

struct S_func_007074c0 {
    char pad0[408];
    int m_value;
    void f(int value);
};

void S_func_007074c0::f(int value)
{
    if (m_value != value) {
        m_value = value;
        sub_00411f60(this, "XSUV3");
    }
}
