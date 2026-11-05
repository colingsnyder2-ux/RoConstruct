// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_006f5d50 {
    T4_006f5d50();
    virtual void f_006f5d50();
    char m_a;
    char m_b;
};
T4_006f5d50::T4_006f5d50() : m_a(0), m_b(0) {}
extern "C" void* create_other_006f5d50(void*, void*, int);
void* create_006f5d50(void* unused, T4_006f5d50* out, int type)
{
    if (type != 4)
        return create_other_006f5d50(unused, out, type);
    out->T4_006f5d50::T4_006f5d50();
    return out;
}
