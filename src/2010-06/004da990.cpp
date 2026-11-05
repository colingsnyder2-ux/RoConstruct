// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_004da990 {
    T4_004da990();
    virtual void f_004da990();
    char m_a;
    char m_b;
};
T4_004da990::T4_004da990() : m_a(0), m_b(0) {}
extern "C" void* create_other_004da990(void*, void*, int);
void* create_004da990(void* unused, T4_004da990* out, int type)
{
    if (type != 4)
        return create_other_004da990(unused, out, type);
    out->T4_004da990::T4_004da990();
    return out;
}
