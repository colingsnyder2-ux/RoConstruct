// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00706700 {
    T4_00706700();
    virtual void f_00706700();
    char m_a;
    char m_b;
};
T4_00706700::T4_00706700() : m_a(0), m_b(0) {}
extern "C" void* create_other_00706700(void*, void*, int);
void* create_00706700(void* unused, T4_00706700* out, int type)
{
    if (type != 4)
        return create_other_00706700(unused, out, type);
    out->T4_00706700::T4_00706700();
    return out;
}
