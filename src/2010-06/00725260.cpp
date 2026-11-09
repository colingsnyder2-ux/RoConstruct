// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00725260 {
    T4_00725260();
    virtual void f_00725260();
    char m_a;
    char m_b;
};
T4_00725260::T4_00725260() : m_a(0), m_b(0) {}
extern "C" void* create_other_00725260(void*, void*, int);
void* create_00725260(void* unused, T4_00725260* out, int type)
{
    if (type != 4)
        return create_other_00725260(unused, out, type);
    out->T4_00725260::T4_00725260();
    return out;
}
