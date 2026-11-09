// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_0041e000 {
    T4_0041e000();
    virtual void f_0041e000();
    char m_a;
    char m_b;
};
T4_0041e000::T4_0041e000() : m_a(0), m_b(0) {}
extern "C" void* create_other_0041e000(void*, void*, int);
void* create_0041e000(void* unused, T4_0041e000* out, int type)
{
    if (type != 4)
        return create_other_0041e000(unused, out, type);
    out->T4_0041e000::T4_0041e000();
    return out;
}
