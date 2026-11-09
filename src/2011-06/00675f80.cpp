// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00675f80 {
    T4_00675f80();
    virtual void f_00675f80();
    char m_a;
    char m_b;
};
T4_00675f80::T4_00675f80() : m_a(0), m_b(0) {}
extern "C" void* create_other_00675f80(void*, void*, int);
void* create_00675f80(void* unused, T4_00675f80* out, int type)
{
    if (type != 4)
        return create_other_00675f80(unused, out, type);
    out->T4_00675f80::T4_00675f80();
    return out;
}
