// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00593c80 {
    T4_00593c80();
    virtual void f_00593c80();
    char m_a;
    char m_b;
};
T4_00593c80::T4_00593c80() : m_a(0), m_b(0) {}
extern "C" void* create_other_00593c80(void*, void*, int);
void* create_00593c80(void* unused, T4_00593c80* out, int type)
{
    if (type != 4)
        return create_other_00593c80(unused, out, type);
    out->T4_00593c80::T4_00593c80();
    return out;
}
