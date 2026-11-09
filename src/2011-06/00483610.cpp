// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00483610 {
    T4_00483610();
    virtual void f_00483610();
    char m_a;
    char m_b;
};
T4_00483610::T4_00483610() : m_a(0), m_b(0) {}
extern "C" void* create_other_00483610(void*, void*, int);
void* create_00483610(void* unused, T4_00483610* out, int type)
{
    if (type != 4)
        return create_other_00483610(unused, out, type);
    out->T4_00483610::T4_00483610();
    return out;
}
