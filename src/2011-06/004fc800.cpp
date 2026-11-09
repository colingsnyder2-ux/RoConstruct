// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_004fc800 {
    T4_004fc800();
    virtual void f_004fc800();
    char m_a;
    char m_b;
};
T4_004fc800::T4_004fc800() : m_a(0), m_b(0) {}
extern "C" void* create_other_004fc800(void*, void*, int);
void* create_004fc800(void* unused, T4_004fc800* out, int type)
{
    if (type != 4)
        return create_other_004fc800(unused, out, type);
    out->T4_004fc800::T4_004fc800();
    return out;
}
