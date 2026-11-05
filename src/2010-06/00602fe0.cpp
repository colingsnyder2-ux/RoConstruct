// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00602fe0 {
    T4_00602fe0();
    virtual void f_00602fe0();
    char m_a;
    char m_b;
};
T4_00602fe0::T4_00602fe0() : m_a(0), m_b(0) {}
extern "C" void* create_other_00602fe0(void*, void*, int);
void* create_00602fe0(void* unused, T4_00602fe0* out, int type)
{
    if (type != 4)
        return create_other_00602fe0(unused, out, type);
    out->T4_00602fe0::T4_00602fe0();
    return out;
}
