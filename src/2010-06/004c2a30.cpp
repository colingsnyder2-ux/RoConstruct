// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_004c2a30 {
    T4_004c2a30();
    virtual void f_004c2a30();
    char m_a;
    char m_b;
};
T4_004c2a30::T4_004c2a30() : m_a(0), m_b(0) {}
extern "C" void* create_other_004c2a30(void*, void*, int);
void* create_004c2a30(void* unused, T4_004c2a30* out, int type)
{
    if (type != 4)
        return create_other_004c2a30(unused, out, type);
    out->T4_004c2a30::T4_004c2a30();
    return out;
}
