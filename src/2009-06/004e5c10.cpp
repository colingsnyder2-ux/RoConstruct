// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_004e5c10 {
    T4_004e5c10();
    virtual void f_004e5c10();
    char m_a;
    char m_b;
};
T4_004e5c10::T4_004e5c10() : m_a(0), m_b(0) {}
extern "C" void* create_other_004e5c10(void*, void*, int);
void* create_004e5c10(void* unused, T4_004e5c10* out, int type)
{
    if (type != 4)
        return create_other_004e5c10(unused, out, type);
    out->T4_004e5c10::T4_004e5c10();
    return out;
}
