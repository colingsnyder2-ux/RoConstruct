// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_004d6b10 {
    T4_004d6b10();
    virtual void f_004d6b10();
    char m_a;
    char m_b;
};
T4_004d6b10::T4_004d6b10() : m_a(0), m_b(0) {}
extern "C" void* create_other_004d6b10(void*, void*, int);
void* create_004d6b10(void* unused, T4_004d6b10* out, int type)
{
    if (type != 4)
        return create_other_004d6b10(unused, out, type);
    out->T4_004d6b10::T4_004d6b10();
    return out;
}
