// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_004e5ca0 {
    T4_004e5ca0();
    virtual void f_004e5ca0();
    char m_a;
    char m_b;
};
T4_004e5ca0::T4_004e5ca0() : m_a(0), m_b(0) {}
extern "C" void* create_other_004e5ca0(void*, void*, int);
void* create_004e5ca0(void* unused, T4_004e5ca0* out, int type)
{
    if (type != 4)
        return create_other_004e5ca0(unused, out, type);
    out->T4_004e5ca0::T4_004e5ca0();
    return out;
}
