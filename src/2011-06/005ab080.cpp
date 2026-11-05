// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_005ab080 {
    T4_005ab080();
    virtual void f_005ab080();
    char m_a;
    char m_b;
};
T4_005ab080::T4_005ab080() : m_a(0), m_b(0) {}
extern "C" void* create_other_005ab080(void*, void*, int);
void* create_005ab080(void* unused, T4_005ab080* out, int type)
{
    if (type != 4)
        return create_other_005ab080(unused, out, type);
    out->T4_005ab080::T4_005ab080();
    return out;
}
