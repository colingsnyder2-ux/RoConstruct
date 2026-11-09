// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00644770 {
    T4_00644770();
    virtual void f_00644770();
    char m_a;
    char m_b;
};
T4_00644770::T4_00644770() : m_a(0), m_b(0) {}
extern "C" void* create_other_00644770(void*, void*, int);
void* create_00644770(void* unused, T4_00644770* out, int type)
{
    if (type != 4)
        return create_other_00644770(unused, out, type);
    out->T4_00644770::T4_00644770();
    return out;
}
