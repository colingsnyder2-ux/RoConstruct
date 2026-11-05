// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_006cb730 {
    T4_006cb730();
    virtual void f_006cb730();
    char m_a;
    char m_b;
};
T4_006cb730::T4_006cb730() : m_a(0), m_b(0) {}
extern "C" void* create_other_006cb730(void*, void*, int);
void* create_006cb730(void* unused, T4_006cb730* out, int type)
{
    if (type != 4)
        return create_other_006cb730(unused, out, type);
    out->T4_006cb730::T4_006cb730();
    return out;
}
