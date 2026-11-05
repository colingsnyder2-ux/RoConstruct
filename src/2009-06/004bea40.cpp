// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_004bea40 {
    T4_004bea40();
    virtual void f_004bea40();
    char m_a;
    char m_b;
};
T4_004bea40::T4_004bea40() : m_a(0), m_b(0) {}
extern "C" void* create_other_004bea40(void*, void*, int);
void* create_004bea40(void* unused, T4_004bea40* out, int type)
{
    if (type != 4)
        return create_other_004bea40(unused, out, type);
    out->T4_004bea40::T4_004bea40();
    return out;
}
