// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_006cfb60 {
    T4_006cfb60();
    virtual void f_006cfb60();
    char m_a;
    char m_b;
};
T4_006cfb60::T4_006cfb60() : m_a(0), m_b(0) {}
extern "C" void* create_other_006cfb60(void*, void*, int);
void* create_006cfb60(void* unused, T4_006cfb60* out, int type)
{
    if (type != 4)
        return create_other_006cfb60(unused, out, type);
    out->T4_006cfb60::T4_006cfb60();
    return out;
}
