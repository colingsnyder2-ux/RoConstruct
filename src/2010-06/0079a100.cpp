// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_0079a100 {
    T4_0079a100();
    virtual void f_0079a100();
    char m_a;
    char m_b;
};
T4_0079a100::T4_0079a100() : m_a(0), m_b(0) {}
extern "C" void* create_other_0079a100(void*, void*, int);
void* create_0079a100(void* unused, T4_0079a100* out, int type)
{
    if (type != 4)
        return create_other_0079a100(unused, out, type);
    out->T4_0079a100::T4_0079a100();
    return out;
}
