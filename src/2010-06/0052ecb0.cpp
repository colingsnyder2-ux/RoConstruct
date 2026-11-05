// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_0052ecb0 {
    T4_0052ecb0();
    virtual void f_0052ecb0();
    char m_a;
    char m_b;
};
T4_0052ecb0::T4_0052ecb0() : m_a(0), m_b(0) {}
extern "C" void* create_other_0052ecb0(void*, void*, int);
void* create_0052ecb0(void* unused, T4_0052ecb0* out, int type)
{
    if (type != 4)
        return create_other_0052ecb0(unused, out, type);
    out->T4_0052ecb0::T4_0052ecb0();
    return out;
}
