// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00519570 {
    T4_00519570();
    virtual void f_00519570();
    char m_a;
    char m_b;
};
T4_00519570::T4_00519570() : m_a(0), m_b(0) {}
extern "C" void* create_other_00519570(void*, void*, int);
void* create_00519570(void* unused, T4_00519570* out, int type)
{
    if (type != 4)
        return create_other_00519570(unused, out, type);
    out->T4_00519570::T4_00519570();
    return out;
}
