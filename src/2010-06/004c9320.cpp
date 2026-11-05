// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_004c9320 {
    T4_004c9320();
    virtual void f_004c9320();
    char m_a;
    char m_b;
};
T4_004c9320::T4_004c9320() : m_a(0), m_b(0) {}
extern "C" void* create_other_004c9320(void*, void*, int);
void* create_004c9320(void* unused, T4_004c9320* out, int type)
{
    if (type != 4)
        return create_other_004c9320(unused, out, type);
    out->T4_004c9320::T4_004c9320();
    return out;
}
