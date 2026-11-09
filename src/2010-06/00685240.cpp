// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00685240 {
    T4_00685240();
    virtual void f_00685240();
    char m_a;
    char m_b;
};
T4_00685240::T4_00685240() : m_a(0), m_b(0) {}
extern "C" void* create_other_00685240(void*, void*, int);
void* create_00685240(void* unused, T4_00685240* out, int type)
{
    if (type != 4)
        return create_other_00685240(unused, out, type);
    out->T4_00685240::T4_00685240();
    return out;
}
