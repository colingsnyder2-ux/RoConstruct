// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00465570 {
    T4_00465570();
    virtual void f_00465570();
    char m_a;
    char m_b;
};
T4_00465570::T4_00465570() : m_a(0), m_b(0) {}
extern "C" void* create_other_00465570(void*, void*, int);
void* create_00465570(void* unused, T4_00465570* out, int type)
{
    if (type != 4)
        return create_other_00465570(unused, out, type);
    out->T4_00465570::T4_00465570();
    return out;
}
