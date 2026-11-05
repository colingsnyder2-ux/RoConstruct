// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00501780 {
    T4_00501780();
    virtual void f_00501780();
    char m_a;
    char m_b;
};
T4_00501780::T4_00501780() : m_a(0), m_b(0) {}
extern "C" void* create_other_00501780(void*, void*, int);
void* create_00501780(void* unused, T4_00501780* out, int type)
{
    if (type != 4)
        return create_other_00501780(unused, out, type);
    out->T4_00501780::T4_00501780();
    return out;
}
