// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_004c2c00 {
    T4_004c2c00();
    virtual void f_004c2c00();
    char m_a;
    char m_b;
};
T4_004c2c00::T4_004c2c00() : m_a(0), m_b(0) {}
extern "C" void* create_other_004c2c00(void*, void*, int);
void* create_004c2c00(void* unused, T4_004c2c00* out, int type)
{
    if (type != 4)
        return create_other_004c2c00(unused, out, type);
    out->T4_004c2c00::T4_004c2c00();
    return out;
}
