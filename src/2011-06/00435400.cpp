// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00435400 {
    T4_00435400();
    virtual void f_00435400();
    char m_a;
    char m_b;
};
T4_00435400::T4_00435400() : m_a(0), m_b(0) {}
extern "C" void* create_other_00435400(void*, void*, int);
void* create_00435400(void* unused, T4_00435400* out, int type)
{
    if (type != 4)
        return create_other_00435400(unused, out, type);
    out->T4_00435400::T4_00435400();
    return out;
}
