// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_004eb900 {
    T4_004eb900();
    virtual void f_004eb900();
    char m_a;
    char m_b;
};
T4_004eb900::T4_004eb900() : m_a(0), m_b(0) {}
extern "C" void* create_other_004eb900(void*, void*, int);
void* create_004eb900(void* unused, T4_004eb900* out, int type)
{
    if (type != 4)
        return create_other_004eb900(unused, out, type);
    out->T4_004eb900::T4_004eb900();
    return out;
}
