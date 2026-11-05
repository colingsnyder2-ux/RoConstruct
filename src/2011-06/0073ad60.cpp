// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_0073ad60 {
    T4_0073ad60();
    virtual void f_0073ad60();
    char m_a;
    char m_b;
};
T4_0073ad60::T4_0073ad60() : m_a(0), m_b(0) {}
extern "C" void* create_other_0073ad60(void*, void*, int);
void* create_0073ad60(void* unused, T4_0073ad60* out, int type)
{
    if (type != 4)
        return create_other_0073ad60(unused, out, type);
    out->T4_0073ad60::T4_0073ad60();
    return out;
}
