// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00465c20 {
    T4_00465c20();
    virtual void f_00465c20();
    char m_a;
    char m_b;
};
T4_00465c20::T4_00465c20() : m_a(0), m_b(0) {}
extern "C" void* create_other_00465c20(void*, void*, int);
void* create_00465c20(void* unused, T4_00465c20* out, int type)
{
    if (type != 4)
        return create_other_00465c20(unused, out, type);
    out->T4_00465c20::T4_00465c20();
    return out;
}
