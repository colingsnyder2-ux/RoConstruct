// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_005097a0 {
    T4_005097a0();
    virtual void f_005097a0();
    char m_a;
    char m_b;
};
T4_005097a0::T4_005097a0() : m_a(0), m_b(0) {}
extern "C" void* create_other_005097a0(void*, void*, int);
void* create_005097a0(void* unused, T4_005097a0* out, int type)
{
    if (type != 4)
        return create_other_005097a0(unused, out, type);
    out->T4_005097a0::T4_005097a0();
    return out;
}
