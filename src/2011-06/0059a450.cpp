// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_0059a450 {
    T4_0059a450();
    virtual void f_0059a450();
    char m_a;
    char m_b;
};
T4_0059a450::T4_0059a450() : m_a(0), m_b(0) {}
extern "C" void* create_other_0059a450(void*, void*, int);
void* create_0059a450(void* unused, T4_0059a450* out, int type)
{
    if (type != 4)
        return create_other_0059a450(unused, out, type);
    out->T4_0059a450::T4_0059a450();
    return out;
}
