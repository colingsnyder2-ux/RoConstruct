// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_004ac000 {
    T4_004ac000();
    virtual void f_004ac000();
    char m_a;
    char m_b;
};
T4_004ac000::T4_004ac000() : m_a(0), m_b(0) {}
extern "C" void* create_other_004ac000(void*, void*, int);
void* create_004ac000(void* unused, T4_004ac000* out, int type)
{
    if (type != 4)
        return create_other_004ac000(unused, out, type);
    out->T4_004ac000::T4_004ac000();
    return out;
}
