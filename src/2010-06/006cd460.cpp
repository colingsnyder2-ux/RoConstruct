// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_006cd460 {
    T4_006cd460();
    virtual void f_006cd460();
    char m_a;
    char m_b;
};
T4_006cd460::T4_006cd460() : m_a(0), m_b(0) {}
extern "C" void* create_other_006cd460(void*, void*, int);
void* create_006cd460(void* unused, T4_006cd460* out, int type)
{
    if (type != 4)
        return create_other_006cd460(unused, out, type);
    out->T4_006cd460::T4_006cd460();
    return out;
}
