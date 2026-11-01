// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_0046bc30 {
    T4_0046bc30();
    virtual void f_0046bc30();
    char m_a;
    char m_b;
};
T4_0046bc30::T4_0046bc30() : m_a(0), m_b(0) {}
extern "C" void* create_other_0046bc30(void*, void*, int);
void* create_0046bc30(void* unused, T4_0046bc30* out, int type)
{
    if (type != 4)
        return create_other_0046bc30(unused, out, type);
    out->T4_0046bc30::T4_0046bc30();
    return out;
}
