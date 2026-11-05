// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00458640 {
    T4_00458640();
    virtual void f_00458640();
    char m_a;
    char m_b;
};
T4_00458640::T4_00458640() : m_a(0), m_b(0) {}
extern "C" void* create_other_00458640(void*, void*, int);
void* create_00458640(void* unused, T4_00458640* out, int type)
{
    if (type != 4)
        return create_other_00458640(unused, out, type);
    out->T4_00458640::T4_00458640();
    return out;
}
