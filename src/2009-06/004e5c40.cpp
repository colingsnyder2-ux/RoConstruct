// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_004e5c40 {
    T4_004e5c40();
    virtual void f_004e5c40();
    char m_a;
    char m_b;
};
T4_004e5c40::T4_004e5c40() : m_a(0), m_b(0) {}
extern "C" void* create_other_004e5c40(void*, void*, int);
void* create_004e5c40(void* unused, T4_004e5c40* out, int type)
{
    if (type != 4)
        return create_other_004e5c40(unused, out, type);
    out->T4_004e5c40::T4_004e5c40();
    return out;
}
