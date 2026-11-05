// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_0042bb80 {
    T4_0042bb80();
    virtual void f_0042bb80();
    char m_a;
    char m_b;
};
T4_0042bb80::T4_0042bb80() : m_a(0), m_b(0) {}
extern "C" void* create_other_0042bb80(void*, void*, int);
void* create_0042bb80(void* unused, T4_0042bb80* out, int type)
{
    if (type != 4)
        return create_other_0042bb80(unused, out, type);
    out->T4_0042bb80::T4_0042bb80();
    return out;
}
