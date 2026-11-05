// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_0041a290 {
    T4_0041a290();
    virtual void f_0041a290();
    char m_a;
    char m_b;
};
T4_0041a290::T4_0041a290() : m_a(0), m_b(0) {}
extern "C" void* create_other_0041a290(void*, void*, int);
void* create_0041a290(void* unused, T4_0041a290* out, int type)
{
    if (type != 4)
        return create_other_0041a290(unused, out, type);
    out->T4_0041a290::T4_0041a290();
    return out;
}
