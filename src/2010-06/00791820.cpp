// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00791820 {
    T4_00791820();
    virtual void f_00791820();
    char m_a;
    char m_b;
};
T4_00791820::T4_00791820() : m_a(0), m_b(0) {}
extern "C" void* create_other_00791820(void*, void*, int);
void* create_00791820(void* unused, T4_00791820* out, int type)
{
    if (type != 4)
        return create_other_00791820(unused, out, type);
    out->T4_00791820::T4_00791820();
    return out;
}
