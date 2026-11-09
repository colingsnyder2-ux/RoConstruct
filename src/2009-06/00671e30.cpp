// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00671e30 {
    T4_00671e30();
    virtual void f_00671e30();
    char m_a;
    char m_b;
};
T4_00671e30::T4_00671e30() : m_a(0), m_b(0) {}
extern "C" void* create_other_00671e30(void*, void*, int);
void* create_00671e30(void* unused, T4_00671e30* out, int type)
{
    if (type != 4)
        return create_other_00671e30(unused, out, type);
    out->T4_00671e30::T4_00671e30();
    return out;
}
