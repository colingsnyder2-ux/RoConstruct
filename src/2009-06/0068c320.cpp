// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_0068c320 {
    T4_0068c320();
    virtual void f_0068c320();
    char m_a;
    char m_b;
};
T4_0068c320::T4_0068c320() : m_a(0), m_b(0) {}
extern "C" void* create_other_0068c320(void*, void*, int);
void* create_0068c320(void* unused, T4_0068c320* out, int type)
{
    if (type != 4)
        return create_other_0068c320(unused, out, type);
    out->T4_0068c320::T4_0068c320();
    return out;
}
