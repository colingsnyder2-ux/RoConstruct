// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_0060fd80 {
    T4_0060fd80();
    virtual void f_0060fd80();
    char m_a;
    char m_b;
};
T4_0060fd80::T4_0060fd80() : m_a(0), m_b(0) {}
extern "C" void* create_other_0060fd80(void*, void*, int);
void* create_0060fd80(void* unused, T4_0060fd80* out, int type)
{
    if (type != 4)
        return create_other_0060fd80(unused, out, type);
    out->T4_0060fd80::T4_0060fd80();
    return out;
}
