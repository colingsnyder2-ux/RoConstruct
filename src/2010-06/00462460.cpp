// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00462460 {
    T4_00462460();
    virtual void f_00462460();
    char m_a;
    char m_b;
};
T4_00462460::T4_00462460() : m_a(0), m_b(0) {}
extern "C" void* create_other_00462460(void*, void*, int);
void* create_00462460(void* unused, T4_00462460* out, int type)
{
    if (type != 4)
        return create_other_00462460(unused, out, type);
    out->T4_00462460::T4_00462460();
    return out;
}
