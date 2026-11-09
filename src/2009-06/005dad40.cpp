// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_005dad40 {
    T4_005dad40();
    virtual void f_005dad40();
    char m_a;
    char m_b;
};
T4_005dad40::T4_005dad40() : m_a(0), m_b(0) {}
extern "C" void* create_other_005dad40(void*, void*, int);
void* create_005dad40(void* unused, T4_005dad40* out, int type)
{
    if (type != 4)
        return create_other_005dad40(unused, out, type);
    out->T4_005dad40::T4_005dad40();
    return out;
}
