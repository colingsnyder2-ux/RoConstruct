// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_007fc340 {
    T4_007fc340();
    virtual void f_007fc340();
    char m_a;
    char m_b;
};
T4_007fc340::T4_007fc340() : m_a(0), m_b(0) {}
extern "C" void* create_other_007fc340(void*, void*, int);
void* create_007fc340(void* unused, T4_007fc340* out, int type)
{
    if (type != 4)
        return create_other_007fc340(unused, out, type);
    out->T4_007fc340::T4_007fc340();
    return out;
}
