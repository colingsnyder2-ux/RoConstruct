// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00435a00 {
    T4_00435a00();
    virtual void f_00435a00();
    char m_a;
    char m_b;
};
T4_00435a00::T4_00435a00() : m_a(0), m_b(0) {}
extern "C" void* create_other_00435a00(void*, void*, int);
void* create_00435a00(void* unused, T4_00435a00* out, int type)
{
    if (type != 4)
        return create_other_00435a00(unused, out, type);
    out->T4_00435a00::T4_00435a00();
    return out;
}
