// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_006c7760 {
    T4_006c7760();
    virtual void f_006c7760();
    char m_a;
    char m_b;
};
T4_006c7760::T4_006c7760() : m_a(0), m_b(0) {}
extern "C" void* create_other_006c7760(void*, void*, int);
void* create_006c7760(void* unused, T4_006c7760* out, int type)
{
    if (type != 4)
        return create_other_006c7760(unused, out, type);
    out->T4_006c7760::T4_006c7760();
    return out;
}
