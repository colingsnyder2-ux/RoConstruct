// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00698510 {
    T4_00698510();
    virtual void f_00698510();
    char m_a;
    char m_b;
};
T4_00698510::T4_00698510() : m_a(0), m_b(0) {}
extern "C" void* create_other_00698510(void*, void*, int);
void* create_00698510(void* unused, T4_00698510* out, int type)
{
    if (type != 4)
        return create_other_00698510(unused, out, type);
    out->T4_00698510::T4_00698510();
    return out;
}
