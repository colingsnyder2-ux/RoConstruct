// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_005ff570 {
    T4_005ff570();
    virtual void f_005ff570();
    char m_a;
    char m_b;
};
T4_005ff570::T4_005ff570() : m_a(0), m_b(0) {}
extern "C" void* create_other_005ff570(void*, void*, int);
void* create_005ff570(void* unused, T4_005ff570* out, int type)
{
    if (type != 4)
        return create_other_005ff570(unused, out, type);
    out->T4_005ff570::T4_005ff570();
    return out;
}
