// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00697980 {
    T4_00697980();
    virtual void f_00697980();
    char m_a;
    char m_b;
};
T4_00697980::T4_00697980() : m_a(0), m_b(0) {}
extern "C" void* create_other_00697980(void*, void*, int);
void* create_00697980(void* unused, T4_00697980* out, int type)
{
    if (type != 4)
        return create_other_00697980(unused, out, type);
    out->T4_00697980::T4_00697980();
    return out;
}
