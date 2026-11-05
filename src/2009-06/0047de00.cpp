// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_0047de00 {
    T4_0047de00();
    virtual void f_0047de00();
    char m_a;
    char m_b;
};
T4_0047de00::T4_0047de00() : m_a(0), m_b(0) {}
extern "C" void* create_other_0047de00(void*, void*, int);
void* create_0047de00(void* unused, T4_0047de00* out, int type)
{
    if (type != 4)
        return create_other_0047de00(unused, out, type);
    out->T4_0047de00::T4_0047de00();
    return out;
}
