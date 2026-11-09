// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_0069b000 {
    T4_0069b000();
    virtual void f_0069b000();
    char m_a;
    char m_b;
};
T4_0069b000::T4_0069b000() : m_a(0), m_b(0) {}
extern "C" void* create_other_0069b000(void*, void*, int);
void* create_0069b000(void* unused, T4_0069b000* out, int type)
{
    if (type != 4)
        return create_other_0069b000(unused, out, type);
    out->T4_0069b000::T4_0069b000();
    return out;
}
