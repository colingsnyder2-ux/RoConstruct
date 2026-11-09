// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00528b40 {
    T4_00528b40();
    virtual void f_00528b40();
    char m_a;
    char m_b;
};
T4_00528b40::T4_00528b40() : m_a(0), m_b(0) {}
extern "C" void* create_other_00528b40(void*, void*, int);
void* create_00528b40(void* unused, T4_00528b40* out, int type)
{
    if (type != 4)
        return create_other_00528b40(unused, out, type);
    out->T4_00528b40::T4_00528b40();
    return out;
}
