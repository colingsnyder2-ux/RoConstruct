// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_0065f690 {
    T4_0065f690();
    virtual void f_0065f690();
    char m_a;
    char m_b;
};
T4_0065f690::T4_0065f690() : m_a(0), m_b(0) {}
extern "C" void* create_other_0065f690(void*, void*, int);
void* create_0065f690(void* unused, T4_0065f690* out, int type)
{
    if (type != 4)
        return create_other_0065f690(unused, out, type);
    out->T4_0065f690::T4_0065f690();
    return out;
}
