// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00678190 {
    T4_00678190();
    virtual void f_00678190();
    char m_a;
    char m_b;
};
T4_00678190::T4_00678190() : m_a(0), m_b(0) {}
extern "C" void* create_other_00678190(void*, void*, int);
void* create_00678190(void* unused, T4_00678190* out, int type)
{
    if (type != 4)
        return create_other_00678190(unused, out, type);
    out->T4_00678190::T4_00678190();
    return out;
}
