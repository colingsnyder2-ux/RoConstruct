// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_0041b600 {
    T4_0041b600();
    virtual void f_0041b600();
    char m_a;
    char m_b;
};
T4_0041b600::T4_0041b600() : m_a(0), m_b(0) {}
extern "C" void* create_other_0041b600(void*, void*, int);
void* create_0041b600(void* unused, T4_0041b600* out, int type)
{
    if (type != 4)
        return create_other_0041b600(unused, out, type);
    out->T4_0041b600::T4_0041b600();
    return out;
}
