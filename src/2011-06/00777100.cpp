// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00777100 {
    T4_00777100();
    virtual void f_00777100();
    char m_a;
    char m_b;
};
T4_00777100::T4_00777100() : m_a(0), m_b(0) {}
extern "C" void* create_other_00777100(void*, void*, int);
void* create_00777100(void* unused, T4_00777100* out, int type)
{
    if (type != 4)
        return create_other_00777100(unused, out, type);
    out->T4_00777100::T4_00777100();
    return out;
}
