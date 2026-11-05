// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_005cf540 {
    T4_005cf540();
    virtual void f_005cf540();
    char m_a;
    char m_b;
};
T4_005cf540::T4_005cf540() : m_a(0), m_b(0) {}
extern "C" void* create_other_005cf540(void*, void*, int);
void* create_005cf540(void* unused, T4_005cf540* out, int type)
{
    if (type != 4)
        return create_other_005cf540(unused, out, type);
    out->T4_005cf540::T4_005cf540();
    return out;
}
