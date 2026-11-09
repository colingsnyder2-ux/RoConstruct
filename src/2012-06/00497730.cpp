// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00497730 {
    T4_00497730();
    virtual void f_00497730();
    char m_a;
    char m_b;
};
T4_00497730::T4_00497730() : m_a(0), m_b(0) {}
extern "C" void* create_other_00497730(void*, void*, int);
void* create_00497730(void* unused, T4_00497730* out, int type)
{
    if (type != 4)
        return create_other_00497730(unused, out, type);
    out->T4_00497730::T4_00497730();
    return out;
}
