// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_0059e180 {
    T4_0059e180();
    virtual void f_0059e180();
    char m_a;
    char m_b;
};
T4_0059e180::T4_0059e180() : m_a(0), m_b(0) {}
extern "C" void* create_other_0059e180(void*, void*, int);
void* create_0059e180(void* unused, T4_0059e180* out, int type)
{
    if (type != 4)
        return create_other_0059e180(unused, out, type);
    out->T4_0059e180::T4_0059e180();
    return out;
}
