// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_0052ed10 {
    T4_0052ed10();
    virtual void f_0052ed10();
    char m_a;
    char m_b;
};
T4_0052ed10::T4_0052ed10() : m_a(0), m_b(0) {}
extern "C" void* create_other_0052ed10(void*, void*, int);
void* create_0052ed10(void* unused, T4_0052ed10* out, int type)
{
    if (type != 4)
        return create_other_0052ed10(unused, out, type);
    out->T4_0052ed10::T4_0052ed10();
    return out;
}
