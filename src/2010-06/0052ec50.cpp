// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_0052ec50 {
    T4_0052ec50();
    virtual void f_0052ec50();
    char m_a;
    char m_b;
};
T4_0052ec50::T4_0052ec50() : m_a(0), m_b(0) {}
extern "C" void* create_other_0052ec50(void*, void*, int);
void* create_0052ec50(void* unused, T4_0052ec50* out, int type)
{
    if (type != 4)
        return create_other_0052ec50(unused, out, type);
    out->T4_0052ec50::T4_0052ec50();
    return out;
}
