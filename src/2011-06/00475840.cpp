// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00475840 {
    T4_00475840();
    virtual void f_00475840();
    char m_a;
    char m_b;
};
T4_00475840::T4_00475840() : m_a(0), m_b(0) {}
extern "C" void* create_other_00475840(void*, void*, int);
void* create_00475840(void* unused, T4_00475840* out, int type)
{
    if (type != 4)
        return create_other_00475840(unused, out, type);
    out->T4_00475840::T4_00475840();
    return out;
}
