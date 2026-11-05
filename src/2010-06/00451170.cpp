// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00451170 {
    T4_00451170();
    virtual void f_00451170();
    char m_a;
    char m_b;
};
T4_00451170::T4_00451170() : m_a(0), m_b(0) {}
extern "C" void* create_other_00451170(void*, void*, int);
void* create_00451170(void* unused, T4_00451170* out, int type)
{
    if (type != 4)
        return create_other_00451170(unused, out, type);
    out->T4_00451170::T4_00451170();
    return out;
}
