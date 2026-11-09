// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00477120 {
    T4_00477120();
    virtual void f_00477120();
    char m_a;
    char m_b;
};
T4_00477120::T4_00477120() : m_a(0), m_b(0) {}
extern "C" void* create_other_00477120(void*, void*, int);
void* create_00477120(void* unused, T4_00477120* out, int type)
{
    if (type != 4)
        return create_other_00477120(unused, out, type);
    out->T4_00477120::T4_00477120();
    return out;
}
