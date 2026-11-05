// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_0062c810 {
    T4_0062c810();
    virtual void f_0062c810();
    char m_a;
    char m_b;
};
T4_0062c810::T4_0062c810() : m_a(0), m_b(0) {}
extern "C" void* create_other_0062c810(void*, void*, int);
void* create_0062c810(void* unused, T4_0062c810* out, int type)
{
    if (type != 4)
        return create_other_0062c810(unused, out, type);
    out->T4_0062c810::T4_0062c810();
    return out;
}
