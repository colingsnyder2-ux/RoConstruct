// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_0062c750 {
    T4_0062c750();
    virtual void f_0062c750();
    char m_a;
    char m_b;
};
T4_0062c750::T4_0062c750() : m_a(0), m_b(0) {}
extern "C" void* create_other_0062c750(void*, void*, int);
void* create_0062c750(void* unused, T4_0062c750* out, int type)
{
    if (type != 4)
        return create_other_0062c750(unused, out, type);
    out->T4_0062c750::T4_0062c750();
    return out;
}
