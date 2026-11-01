// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_0043d580 {
    T4_0043d580();
    virtual void f_0043d580();
    char m_a;
    char m_b;
};
T4_0043d580::T4_0043d580() : m_a(0), m_b(0) {}
extern "C" void* create_other_0043d580(void*, void*, int);
void* create_0043d580(void* unused, T4_0043d580* out, int type)
{
    if (type != 4)
        return create_other_0043d580(unused, out, type);
    out->T4_0043d580::T4_0043d580();
    return out;
}
