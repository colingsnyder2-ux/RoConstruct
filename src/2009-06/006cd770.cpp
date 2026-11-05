// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_006cd770 {
    T4_006cd770();
    virtual void f_006cd770();
    char m_a;
    char m_b;
};
T4_006cd770::T4_006cd770() : m_a(0), m_b(0) {}
extern "C" void* create_other_006cd770(void*, void*, int);
void* create_006cd770(void* unused, T4_006cd770* out, int type)
{
    if (type != 4)
        return create_other_006cd770(unused, out, type);
    out->T4_006cd770::T4_006cd770();
    return out;
}
