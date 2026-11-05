// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00636450 {
    T4_00636450();
    virtual void f_00636450();
    char m_a;
    char m_b;
};
T4_00636450::T4_00636450() : m_a(0), m_b(0) {}
extern "C" void* create_other_00636450(void*, void*, int);
void* create_00636450(void* unused, T4_00636450* out, int type)
{
    if (type != 4)
        return create_other_00636450(unused, out, type);
    out->T4_00636450::T4_00636450();
    return out;
}
