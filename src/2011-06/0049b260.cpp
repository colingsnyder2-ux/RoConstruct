// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_0049b260 {
    T4_0049b260();
    virtual void f_0049b260();
    char m_a;
    char m_b;
};
T4_0049b260::T4_0049b260() : m_a(0), m_b(0) {}
extern "C" void* create_other_0049b260(void*, void*, int);
void* create_0049b260(void* unused, T4_0049b260* out, int type)
{
    if (type != 4)
        return create_other_0049b260(unused, out, type);
    out->T4_0049b260::T4_0049b260();
    return out;
}
