// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_0067ca10 {
    T4_0067ca10();
    virtual void f_0067ca10();
    char m_a;
    char m_b;
};
T4_0067ca10::T4_0067ca10() : m_a(0), m_b(0) {}
extern "C" void* create_other_0067ca10(void*, void*, int);
void* create_0067ca10(void* unused, T4_0067ca10* out, int type)
{
    if (type != 4)
        return create_other_0067ca10(unused, out, type);
    out->T4_0067ca10::T4_0067ca10();
    return out;
}
