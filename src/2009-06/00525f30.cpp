// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00525f30 {
    T4_00525f30();
    virtual void f_00525f30();
    char m_a;
    char m_b;
};
T4_00525f30::T4_00525f30() : m_a(0), m_b(0) {}
extern "C" void* create_other_00525f30(void*, void*, int);
void* create_00525f30(void* unused, T4_00525f30* out, int type)
{
    if (type != 4)
        return create_other_00525f30(unused, out, type);
    out->T4_00525f30::T4_00525f30();
    return out;
}
