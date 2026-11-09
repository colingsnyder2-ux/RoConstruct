// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_005f3680 {
    T4_005f3680();
    virtual void f_005f3680();
    char m_a;
    char m_b;
};
T4_005f3680::T4_005f3680() : m_a(0), m_b(0) {}
extern "C" void* create_other_005f3680(void*, void*, int);
void* create_005f3680(void* unused, T4_005f3680* out, int type)
{
    if (type != 4)
        return create_other_005f3680(unused, out, type);
    out->T4_005f3680::T4_005f3680();
    return out;
}
