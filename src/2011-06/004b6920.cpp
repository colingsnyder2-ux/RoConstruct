// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_004b6920 {
    T4_004b6920();
    virtual void f_004b6920();
    char m_a;
    char m_b;
};
T4_004b6920::T4_004b6920() : m_a(0), m_b(0) {}
extern "C" void* create_other_004b6920(void*, void*, int);
void* create_004b6920(void* unused, T4_004b6920* out, int type)
{
    if (type != 4)
        return create_other_004b6920(unused, out, type);
    out->T4_004b6920::T4_004b6920();
    return out;
}
