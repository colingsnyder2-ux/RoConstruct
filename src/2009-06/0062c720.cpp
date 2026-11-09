// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_0062c720 {
    T4_0062c720();
    virtual void f_0062c720();
    char m_a;
    char m_b;
};
T4_0062c720::T4_0062c720() : m_a(0), m_b(0) {}
extern "C" void* create_other_0062c720(void*, void*, int);
void* create_0062c720(void* unused, T4_0062c720* out, int type)
{
    if (type != 4)
        return create_other_0062c720(unused, out, type);
    out->T4_0062c720::T4_0062c720();
    return out;
}
