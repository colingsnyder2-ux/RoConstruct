// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_004ea280 {
    T4_004ea280();
    virtual void f_004ea280();
    char m_a;
    char m_b;
};
T4_004ea280::T4_004ea280() : m_a(0), m_b(0) {}
extern "C" void* create_other_004ea280(void*, void*, int);
void* create_004ea280(void* unused, T4_004ea280* out, int type)
{
    if (type != 4)
        return create_other_004ea280(unused, out, type);
    out->T4_004ea280::T4_004ea280();
    return out;
}
