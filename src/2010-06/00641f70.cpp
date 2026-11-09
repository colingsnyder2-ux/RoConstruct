// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00641f70 {
    T4_00641f70();
    virtual void f_00641f70();
    char m_a;
    char m_b;
};
T4_00641f70::T4_00641f70() : m_a(0), m_b(0) {}
extern "C" void* create_other_00641f70(void*, void*, int);
void* create_00641f70(void* unused, T4_00641f70* out, int type)
{
    if (type != 4)
        return create_other_00641f70(unused, out, type);
    out->T4_00641f70::T4_00641f70();
    return out;
}
