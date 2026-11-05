// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00519540 {
    T4_00519540();
    virtual void f_00519540();
    char m_a;
    char m_b;
};
T4_00519540::T4_00519540() : m_a(0), m_b(0) {}
extern "C" void* create_other_00519540(void*, void*, int);
void* create_00519540(void* unused, T4_00519540* out, int type)
{
    if (type != 4)
        return create_other_00519540(unused, out, type);
    out->T4_00519540::T4_00519540();
    return out;
}
