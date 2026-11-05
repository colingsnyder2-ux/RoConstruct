// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00602f50 {
    T4_00602f50();
    virtual void f_00602f50();
    char m_a;
    char m_b;
};
T4_00602f50::T4_00602f50() : m_a(0), m_b(0) {}
extern "C" void* create_other_00602f50(void*, void*, int);
void* create_00602f50(void* unused, T4_00602f50* out, int type)
{
    if (type != 4)
        return create_other_00602f50(unused, out, type);
    out->T4_00602f50::T4_00602f50();
    return out;
}
