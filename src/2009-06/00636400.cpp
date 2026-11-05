// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00636400 {
    T4_00636400();
    virtual void f_00636400();
    char m_a;
    char m_b;
};
T4_00636400::T4_00636400() : m_a(0), m_b(0) {}
extern "C" void* create_other_00636400(void*, void*, int);
void* create_00636400(void* unused, T4_00636400* out, int type)
{
    if (type != 4)
        return create_other_00636400(unused, out, type);
    out->T4_00636400::T4_00636400();
    return out;
}
