// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_0041b130 {
    T4_0041b130();
    virtual void f_0041b130();
    char m_a;
    char m_b;
};
T4_0041b130::T4_0041b130() : m_a(0), m_b(0) {}
extern "C" void* create_other_0041b130(void*, void*, int);
void* create_0041b130(void* unused, T4_0041b130* out, int type)
{
    if (type != 4)
        return create_other_0041b130(unused, out, type);
    out->T4_0041b130::T4_0041b130();
    return out;
}
