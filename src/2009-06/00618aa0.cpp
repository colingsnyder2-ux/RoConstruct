// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00618aa0 {
    T4_00618aa0();
    virtual void f_00618aa0();
    char m_a;
    char m_b;
};
T4_00618aa0::T4_00618aa0() : m_a(0), m_b(0) {}
extern "C" void* create_other_00618aa0(void*, void*, int);
void* create_00618aa0(void* unused, T4_00618aa0* out, int type)
{
    if (type != 4)
        return create_other_00618aa0(unused, out, type);
    out->T4_00618aa0::T4_00618aa0();
    return out;
}
