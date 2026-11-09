// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00706030 {
    T4_00706030();
    virtual void f_00706030();
    char m_a;
    char m_b;
};
T4_00706030::T4_00706030() : m_a(0), m_b(0) {}
extern "C" void* create_other_00706030(void*, void*, int);
void* create_00706030(void* unused, T4_00706030* out, int type)
{
    if (type != 4)
        return create_other_00706030(unused, out, type);
    out->T4_00706030::T4_00706030();
    return out;
}
