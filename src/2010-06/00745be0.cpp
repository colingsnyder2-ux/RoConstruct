// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00745be0 {
    T4_00745be0();
    virtual void f_00745be0();
    char m_a;
    char m_b;
};
T4_00745be0::T4_00745be0() : m_a(0), m_b(0) {}
extern "C" void* create_other_00745be0(void*, void*, int);
void* create_00745be0(void* unused, T4_00745be0* out, int type)
{
    if (type != 4)
        return create_other_00745be0(unused, out, type);
    out->T4_00745be0::T4_00745be0();
    return out;
}
