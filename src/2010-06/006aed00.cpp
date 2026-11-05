// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_006aed00 {
    T4_006aed00();
    virtual void f_006aed00();
    char m_a;
    char m_b;
};
T4_006aed00::T4_006aed00() : m_a(0), m_b(0) {}
extern "C" void* create_other_006aed00(void*, void*, int);
void* create_006aed00(void* unused, T4_006aed00* out, int type)
{
    if (type != 4)
        return create_other_006aed00(unused, out, type);
    out->T4_006aed00::T4_006aed00();
    return out;
}
