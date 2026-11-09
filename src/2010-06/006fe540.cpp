// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_006fe540 {
    T4_006fe540();
    virtual void f_006fe540();
    char m_a;
    char m_b;
};
T4_006fe540::T4_006fe540() : m_a(0), m_b(0) {}
extern "C" void* create_other_006fe540(void*, void*, int);
void* create_006fe540(void* unused, T4_006fe540* out, int type)
{
    if (type != 4)
        return create_other_006fe540(unused, out, type);
    out->T4_006fe540::T4_006fe540();
    return out;
}
