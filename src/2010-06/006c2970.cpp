// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_006c2970 {
    T4_006c2970();
    virtual void f_006c2970();
    char m_a;
    char m_b;
};
T4_006c2970::T4_006c2970() : m_a(0), m_b(0) {}
extern "C" void* create_other_006c2970(void*, void*, int);
void* create_006c2970(void* unused, T4_006c2970* out, int type)
{
    if (type != 4)
        return create_other_006c2970(unused, out, type);
    out->T4_006c2970::T4_006c2970();
    return out;
}
