// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00455550 {
    T4_00455550();
    virtual void f_00455550();
    char m_a;
    char m_b;
};
T4_00455550::T4_00455550() : m_a(0), m_b(0) {}
extern "C" void* create_other_00455550(void*, void*, int);
void* create_00455550(void* unused, T4_00455550* out, int type)
{
    if (type != 4)
        return create_other_00455550(unused, out, type);
    out->T4_00455550::T4_00455550();
    return out;
}
