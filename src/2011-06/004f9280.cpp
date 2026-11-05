// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_004f9280 {
    T4_004f9280();
    virtual void f_004f9280();
    char m_a;
    char m_b;
};
T4_004f9280::T4_004f9280() : m_a(0), m_b(0) {}
extern "C" void* create_other_004f9280(void*, void*, int);
void* create_004f9280(void* unused, T4_004f9280* out, int type)
{
    if (type != 4)
        return create_other_004f9280(unused, out, type);
    out->T4_004f9280::T4_004f9280();
    return out;
}
