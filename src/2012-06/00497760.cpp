// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00497760 {
    T4_00497760();
    virtual void f_00497760();
    char m_a;
    char m_b;
};
T4_00497760::T4_00497760() : m_a(0), m_b(0) {}
extern "C" void* create_other_00497760(void*, void*, int);
void* create_00497760(void* unused, T4_00497760* out, int type)
{
    if (type != 4)
        return create_other_00497760(unused, out, type);
    out->T4_00497760::T4_00497760();
    return out;
}
