// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00746bd0 {
    T4_00746bd0();
    virtual void f_00746bd0();
    char m_a;
    char m_b;
};
T4_00746bd0::T4_00746bd0() : m_a(0), m_b(0) {}
extern "C" void* create_other_00746bd0(void*, void*, int);
void* create_00746bd0(void* unused, T4_00746bd0* out, int type)
{
    if (type != 4)
        return create_other_00746bd0(unused, out, type);
    out->T4_00746bd0::T4_00746bd0();
    return out;
}
