// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_0043ca70 {
    T4_0043ca70();
    virtual void f_0043ca70();
    char m_a;
    char m_b;
};
T4_0043ca70::T4_0043ca70() : m_a(0), m_b(0) {}
extern "C" void* create_other_0043ca70(void*, void*, int);
void* create_0043ca70(void* unused, T4_0043ca70* out, int type)
{
    if (type != 4)
        return create_other_0043ca70(unused, out, type);
    out->T4_0043ca70::T4_0043ca70();
    return out;
}
