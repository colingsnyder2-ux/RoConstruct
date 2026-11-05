// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00725230 {
    T4_00725230();
    virtual void f_00725230();
    char m_a;
    char m_b;
};
T4_00725230::T4_00725230() : m_a(0), m_b(0) {}
extern "C" void* create_other_00725230(void*, void*, int);
void* create_00725230(void* unused, T4_00725230* out, int type)
{
    if (type != 4)
        return create_other_00725230(unused, out, type);
    out->T4_00725230::T4_00725230();
    return out;
}
