// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00685210 {
    T4_00685210();
    virtual void f_00685210();
    char m_a;
    char m_b;
};
T4_00685210::T4_00685210() : m_a(0), m_b(0) {}
extern "C" void* create_other_00685210(void*, void*, int);
void* create_00685210(void* unused, T4_00685210* out, int type)
{
    if (type != 4)
        return create_other_00685210(unused, out, type);
    out->T4_00685210::T4_00685210();
    return out;
}
