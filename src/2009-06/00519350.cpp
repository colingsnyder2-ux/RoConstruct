// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00519350 {
    T4_00519350();
    virtual void f_00519350();
    char m_a;
    char m_b;
};
T4_00519350::T4_00519350() : m_a(0), m_b(0) {}
extern "C" void* create_other_00519350(void*, void*, int);
void* create_00519350(void* unused, T4_00519350* out, int type)
{
    if (type != 4)
        return create_other_00519350(unused, out, type);
    out->T4_00519350::T4_00519350();
    return out;
}
