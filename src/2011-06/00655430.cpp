// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00655430 {
    T4_00655430();
    virtual void f_00655430();
    char m_a;
    char m_b;
};
T4_00655430::T4_00655430() : m_a(0), m_b(0) {}
extern "C" void* create_other_00655430(void*, void*, int);
void* create_00655430(void* unused, T4_00655430* out, int type)
{
    if (type != 4)
        return create_other_00655430(unused, out, type);
    out->T4_00655430::T4_00655430();
    return out;
}
