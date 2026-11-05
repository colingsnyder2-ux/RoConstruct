// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_005fcf70 {
    T4_005fcf70();
    virtual void f_005fcf70();
    char m_a;
    char m_b;
};
T4_005fcf70::T4_005fcf70() : m_a(0), m_b(0) {}
extern "C" void* create_other_005fcf70(void*, void*, int);
void* create_005fcf70(void* unused, T4_005fcf70* out, int type)
{
    if (type != 4)
        return create_other_005fcf70(unused, out, type);
    out->T4_005fcf70::T4_005fcf70();
    return out;
}
