// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00432870 {
    T4_00432870();
    virtual void f_00432870();
    char m_a;
    char m_b;
};
T4_00432870::T4_00432870() : m_a(0), m_b(0) {}
extern "C" void* create_other_00432870(void*, void*, int);
void* create_00432870(void* unused, T4_00432870* out, int type)
{
    if (type != 4)
        return create_other_00432870(unused, out, type);
    out->T4_00432870::T4_00432870();
    return out;
}
