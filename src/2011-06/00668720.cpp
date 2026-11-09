// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00668720 {
    T4_00668720();
    virtual void f_00668720();
    char m_a;
    char m_b;
};
T4_00668720::T4_00668720() : m_a(0), m_b(0) {}
extern "C" void* create_other_00668720(void*, void*, int);
void* create_00668720(void* unused, T4_00668720* out, int type)
{
    if (type != 4)
        return create_other_00668720(unused, out, type);
    out->T4_00668720::T4_00668720();
    return out;
}
