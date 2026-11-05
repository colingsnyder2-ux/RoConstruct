// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_006fcb40 {
    T4_006fcb40();
    virtual void f_006fcb40();
    char m_a;
    char m_b;
};
T4_006fcb40::T4_006fcb40() : m_a(0), m_b(0) {}
extern "C" void* create_other_006fcb40(void*, void*, int);
void* create_006fcb40(void* unused, T4_006fcb40* out, int type)
{
    if (type != 4)
        return create_other_006fcb40(unused, out, type);
    out->T4_006fcb40::T4_006fcb40();
    return out;
}
