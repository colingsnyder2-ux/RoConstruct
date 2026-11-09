// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00601d10 {
    T4_00601d10();
    virtual void f_00601d10();
    char m_a;
    char m_b;
};
T4_00601d10::T4_00601d10() : m_a(0), m_b(0) {}
extern "C" void* create_other_00601d10(void*, void*, int);
void* create_00601d10(void* unused, T4_00601d10* out, int type)
{
    if (type != 4)
        return create_other_00601d10(unused, out, type);
    out->T4_00601d10::T4_00601d10();
    return out;
}
