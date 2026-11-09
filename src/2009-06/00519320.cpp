// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00519320 {
    T4_00519320();
    virtual void f_00519320();
    char m_a;
    char m_b;
};
T4_00519320::T4_00519320() : m_a(0), m_b(0) {}
extern "C" void* create_other_00519320(void*, void*, int);
void* create_00519320(void* unused, T4_00519320* out, int type)
{
    if (type != 4)
        return create_other_00519320(unused, out, type);
    out->T4_00519320::T4_00519320();
    return out;
}
