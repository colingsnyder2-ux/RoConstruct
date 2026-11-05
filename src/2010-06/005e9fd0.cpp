// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_005e9fd0 {
    T4_005e9fd0();
    virtual void f_005e9fd0();
    char m_a;
    char m_b;
};
T4_005e9fd0::T4_005e9fd0() : m_a(0), m_b(0) {}
extern "C" void* create_other_005e9fd0(void*, void*, int);
void* create_005e9fd0(void* unused, T4_005e9fd0* out, int type)
{
    if (type != 4)
        return create_other_005e9fd0(unused, out, type);
    out->T4_005e9fd0::T4_005e9fd0();
    return out;
}
