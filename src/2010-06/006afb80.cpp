// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_006afb80 {
    T4_006afb80();
    virtual void f_006afb80();
    char m_a;
    char m_b;
};
T4_006afb80::T4_006afb80() : m_a(0), m_b(0) {}
extern "C" void* create_other_006afb80(void*, void*, int);
void* create_006afb80(void* unused, T4_006afb80* out, int type)
{
    if (type != 4)
        return create_other_006afb80(unused, out, type);
    out->T4_006afb80::T4_006afb80();
    return out;
}
