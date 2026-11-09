// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00633fc0 {
    T4_00633fc0();
    virtual void f_00633fc0();
    char m_a;
    char m_b;
};
T4_00633fc0::T4_00633fc0() : m_a(0), m_b(0) {}
extern "C" void* create_other_00633fc0(void*, void*, int);
void* create_00633fc0(void* unused, T4_00633fc0* out, int type)
{
    if (type != 4)
        return create_other_00633fc0(unused, out, type);
    out->T4_00633fc0::T4_00633fc0();
    return out;
}
