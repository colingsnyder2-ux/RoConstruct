// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_007015d0 {
    T4_007015d0();
    virtual void f_007015d0();
    char m_a;
    char m_b;
};
T4_007015d0::T4_007015d0() : m_a(0), m_b(0) {}
extern "C" void* create_other_007015d0(void*, void*, int);
void* create_007015d0(void* unused, T4_007015d0* out, int type)
{
    if (type != 4)
        return create_other_007015d0(unused, out, type);
    out->T4_007015d0::T4_007015d0();
    return out;
}
