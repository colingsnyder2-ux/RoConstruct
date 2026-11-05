// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_0045fd20 {
    T4_0045fd20();
    virtual void f_0045fd20();
    char m_a;
    char m_b;
};
T4_0045fd20::T4_0045fd20() : m_a(0), m_b(0) {}
extern "C" void* create_other_0045fd20(void*, void*, int);
void* create_0045fd20(void* unused, T4_0045fd20* out, int type)
{
    if (type != 4)
        return create_other_0045fd20(unused, out, type);
    out->T4_0045fd20::T4_0045fd20();
    return out;
}
