// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_0061ba50 {
    T4_0061ba50();
    virtual void f_0061ba50();
    char m_a;
    char m_b;
};
T4_0061ba50::T4_0061ba50() : m_a(0), m_b(0) {}
extern "C" void* create_other_0061ba50(void*, void*, int);
void* create_0061ba50(void* unused, T4_0061ba50* out, int type)
{
    if (type != 4)
        return create_other_0061ba50(unused, out, type);
    out->T4_0061ba50::T4_0061ba50();
    return out;
}
