// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00512030 {
    T4_00512030();
    virtual void f_00512030();
    char m_a;
    char m_b;
};
T4_00512030::T4_00512030() : m_a(0), m_b(0) {}
extern "C" void* create_other_00512030(void*, void*, int);
void* create_00512030(void* unused, T4_00512030* out, int type)
{
    if (type != 4)
        return create_other_00512030(unused, out, type);
    out->T4_00512030::T4_00512030();
    return out;
}
