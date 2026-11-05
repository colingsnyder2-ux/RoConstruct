// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_0067d900 {
    T4_0067d900();
    virtual void f_0067d900();
    char m_a;
    char m_b;
};
T4_0067d900::T4_0067d900() : m_a(0), m_b(0) {}
extern "C" void* create_other_0067d900(void*, void*, int);
void* create_0067d900(void* unused, T4_0067d900* out, int type)
{
    if (type != 4)
        return create_other_0067d900(unused, out, type);
    out->T4_0067d900::T4_0067d900();
    return out;
}
