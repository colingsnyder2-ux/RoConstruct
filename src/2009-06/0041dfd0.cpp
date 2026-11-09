// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_0041dfd0 {
    T4_0041dfd0();
    virtual void f_0041dfd0();
    char m_a;
    char m_b;
};
T4_0041dfd0::T4_0041dfd0() : m_a(0), m_b(0) {}
extern "C" void* create_other_0041dfd0(void*, void*, int);
void* create_0041dfd0(void* unused, T4_0041dfd0* out, int type)
{
    if (type != 4)
        return create_other_0041dfd0(unused, out, type);
    out->T4_0041dfd0::T4_0041dfd0();
    return out;
}
