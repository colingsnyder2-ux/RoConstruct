// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_0070a1f0 {
    T4_0070a1f0();
    virtual void f_0070a1f0();
    char m_a;
    char m_b;
};
T4_0070a1f0::T4_0070a1f0() : m_a(0), m_b(0) {}
extern "C" void* create_other_0070a1f0(void*, void*, int);
void* create_0070a1f0(void* unused, T4_0070a1f0* out, int type)
{
    if (type != 4)
        return create_other_0070a1f0(unused, out, type);
    out->T4_0070a1f0::T4_0070a1f0();
    return out;
}
