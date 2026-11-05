// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_004d3a60 {
    T4_004d3a60();
    virtual void f_004d3a60();
    char m_a;
    char m_b;
};
T4_004d3a60::T4_004d3a60() : m_a(0), m_b(0) {}
extern "C" void* create_other_004d3a60(void*, void*, int);
void* create_004d3a60(void* unused, T4_004d3a60* out, int type)
{
    if (type != 4)
        return create_other_004d3a60(unused, out, type);
    out->T4_004d3a60::T4_004d3a60();
    return out;
}
