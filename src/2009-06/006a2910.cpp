// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_006a2910 {
    T4_006a2910();
    virtual void f_006a2910();
    char m_a;
    char m_b;
};
T4_006a2910::T4_006a2910() : m_a(0), m_b(0) {}
extern "C" void* create_other_006a2910(void*, void*, int);
void* create_006a2910(void* unused, T4_006a2910* out, int type)
{
    if (type != 4)
        return create_other_006a2910(unused, out, type);
    out->T4_006a2910::T4_006a2910();
    return out;
}
