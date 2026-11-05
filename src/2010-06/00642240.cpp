// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00642240 {
    T4_00642240();
    virtual void f_00642240();
    char m_a;
    char m_b;
};
T4_00642240::T4_00642240() : m_a(0), m_b(0) {}
extern "C" void* create_other_00642240(void*, void*, int);
void* create_00642240(void* unused, T4_00642240* out, int type)
{
    if (type != 4)
        return create_other_00642240(unused, out, type);
    out->T4_00642240::T4_00642240();
    return out;
}
