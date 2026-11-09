// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_005f2fb0 {
    T4_005f2fb0();
    virtual void f_005f2fb0();
    char m_a;
    char m_b;
};
T4_005f2fb0::T4_005f2fb0() : m_a(0), m_b(0) {}
extern "C" void* create_other_005f2fb0(void*, void*, int);
void* create_005f2fb0(void* unused, T4_005f2fb0* out, int type)
{
    if (type != 4)
        return create_other_005f2fb0(unused, out, type);
    out->T4_005f2fb0::T4_005f2fb0();
    return out;
}
