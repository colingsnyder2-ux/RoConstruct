// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00465c50 {
    T4_00465c50();
    virtual void f_00465c50();
    char m_a;
    char m_b;
};
T4_00465c50::T4_00465c50() : m_a(0), m_b(0) {}
extern "C" void* create_other_00465c50(void*, void*, int);
void* create_00465c50(void* unused, T4_00465c50* out, int type)
{
    if (type != 4)
        return create_other_00465c50(unused, out, type);
    out->T4_00465c50::T4_00465c50();
    return out;
}
