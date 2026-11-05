// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00441990 {
    T4_00441990();
    virtual void f_00441990();
    char m_a;
    char m_b;
};
T4_00441990::T4_00441990() : m_a(0), m_b(0) {}
extern "C" void* create_other_00441990(void*, void*, int);
void* create_00441990(void* unused, T4_00441990* out, int type)
{
    if (type != 4)
        return create_other_00441990(unused, out, type);
    out->T4_00441990::T4_00441990();
    return out;
}
