// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00435270 {
    T4_00435270();
    virtual void f_00435270();
    char m_a;
    char m_b;
};
T4_00435270::T4_00435270() : m_a(0), m_b(0) {}
extern "C" void* create_other_00435270(void*, void*, int);
void* create_00435270(void* unused, T4_00435270* out, int type)
{
    if (type != 4)
        return create_other_00435270(unused, out, type);
    out->T4_00435270::T4_00435270();
    return out;
}
