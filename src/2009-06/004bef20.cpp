// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_004bef20 {
    T4_004bef20();
    virtual void f_004bef20();
    char m_a;
    char m_b;
};
T4_004bef20::T4_004bef20() : m_a(0), m_b(0) {}
extern "C" void* create_other_004bef20(void*, void*, int);
void* create_004bef20(void* unused, T4_004bef20* out, int type)
{
    if (type != 4)
        return create_other_004bef20(unused, out, type);
    out->T4_004bef20::T4_004bef20();
    return out;
}
