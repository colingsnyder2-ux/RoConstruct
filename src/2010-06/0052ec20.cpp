// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_0052ec20 {
    T4_0052ec20();
    virtual void f_0052ec20();
    char m_a;
    char m_b;
};
T4_0052ec20::T4_0052ec20() : m_a(0), m_b(0) {}
extern "C" void* create_other_0052ec20(void*, void*, int);
void* create_0052ec20(void* unused, T4_0052ec20* out, int type)
{
    if (type != 4)
        return create_other_0052ec20(unused, out, type);
    out->T4_0052ec20::T4_0052ec20();
    return out;
}
