// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00636530 {
    T4_00636530();
    virtual void f_00636530();
    char m_a;
    char m_b;
};
T4_00636530::T4_00636530() : m_a(0), m_b(0) {}
extern "C" void* create_other_00636530(void*, void*, int);
void* create_00636530(void* unused, T4_00636530* out, int type)
{
    if (type != 4)
        return create_other_00636530(unused, out, type);
    out->T4_00636530::T4_00636530();
    return out;
}
