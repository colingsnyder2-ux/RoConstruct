// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_0063f210 {
    T4_0063f210();
    virtual void f_0063f210();
    char m_a;
    char m_b;
};
T4_0063f210::T4_0063f210() : m_a(0), m_b(0) {}
extern "C" void* create_other_0063f210(void*, void*, int);
void* create_0063f210(void* unused, T4_0063f210* out, int type)
{
    if (type != 4)
        return create_other_0063f210(unused, out, type);
    out->T4_0063f210::T4_0063f210();
    return out;
}
