// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_004abd80 {
    T4_004abd80();
    virtual void f_004abd80();
    char m_a;
    char m_b;
};
T4_004abd80::T4_004abd80() : m_a(0), m_b(0) {}
extern "C" void* create_other_004abd80(void*, void*, int);
void* create_004abd80(void* unused, T4_004abd80* out, int type)
{
    if (type != 4)
        return create_other_004abd80(unused, out, type);
    out->T4_004abd80::T4_004abd80();
    return out;
}
