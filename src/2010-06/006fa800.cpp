// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_006fa800 {
    T4_006fa800();
    virtual void f_006fa800();
    char m_a;
    char m_b;
};
T4_006fa800::T4_006fa800() : m_a(0), m_b(0) {}
extern "C" void* create_other_006fa800(void*, void*, int);
void* create_006fa800(void* unused, T4_006fa800* out, int type)
{
    if (type != 4)
        return create_other_006fa800(unused, out, type);
    out->T4_006fa800::T4_006fa800();
    return out;
}
