// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00449a10 {
    T4_00449a10();
    virtual void f_00449a10();
    char m_a;
    char m_b;
};
T4_00449a10::T4_00449a10() : m_a(0), m_b(0) {}
extern "C" void* create_other_00449a10(void*, void*, int);
void* create_00449a10(void* unused, T4_00449a10* out, int type)
{
    if (type != 4)
        return create_other_00449a10(unused, out, type);
    out->T4_00449a10::T4_00449a10();
    return out;
}
