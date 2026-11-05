// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_004ba620 {
    T4_004ba620();
    virtual void f_004ba620();
    char m_a;
    char m_b;
};
T4_004ba620::T4_004ba620() : m_a(0), m_b(0) {}
extern "C" void* create_other_004ba620(void*, void*, int);
void* create_004ba620(void* unused, T4_004ba620* out, int type)
{
    if (type != 4)
        return create_other_004ba620(unused, out, type);
    out->T4_004ba620::T4_004ba620();
    return out;
}
