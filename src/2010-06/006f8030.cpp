// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_006f8030 {
    T4_006f8030();
    virtual void f_006f8030();
    char m_a;
    char m_b;
};
T4_006f8030::T4_006f8030() : m_a(0), m_b(0) {}
extern "C" void* create_other_006f8030(void*, void*, int);
void* create_006f8030(void* unused, T4_006f8030* out, int type)
{
    if (type != 4)
        return create_other_006f8030(unused, out, type);
    out->T4_006f8030::T4_006f8030();
    return out;
}
