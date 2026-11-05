// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_0042fbb0 {
    T4_0042fbb0();
    virtual void f_0042fbb0();
    char m_a;
    char m_b;
};
T4_0042fbb0::T4_0042fbb0() : m_a(0), m_b(0) {}
extern "C" void* create_other_0042fbb0(void*, void*, int);
void* create_0042fbb0(void* unused, T4_0042fbb0* out, int type)
{
    if (type != 4)
        return create_other_0042fbb0(unused, out, type);
    out->T4_0042fbb0::T4_0042fbb0();
    return out;
}
