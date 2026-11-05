// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_006cb6d0 {
    T4_006cb6d0();
    virtual void f_006cb6d0();
    char m_a;
    char m_b;
};
T4_006cb6d0::T4_006cb6d0() : m_a(0), m_b(0) {}
extern "C" void* create_other_006cb6d0(void*, void*, int);
void* create_006cb6d0(void* unused, T4_006cb6d0* out, int type)
{
    if (type != 4)
        return create_other_006cb6d0(unused, out, type);
    out->T4_006cb6d0::T4_006cb6d0();
    return out;
}
