// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00455470 {
    T4_00455470();
    virtual void f_00455470();
    char m_a;
    char m_b;
};
T4_00455470::T4_00455470() : m_a(0), m_b(0) {}
extern "C" void* create_other_00455470(void*, void*, int);
void* create_00455470(void* unused, T4_00455470* out, int type)
{
    if (type != 4)
        return create_other_00455470(unused, out, type);
    out->T4_00455470::T4_00455470();
    return out;
}
