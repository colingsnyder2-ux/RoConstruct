// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00909410 {
    T4_00909410();
    virtual void f_00909410();
    char m_a;
    char m_b;
};
T4_00909410::T4_00909410() : m_a(0), m_b(0) {}
extern "C" void* create_other_00909410(void*, void*, int);
void* create_00909410(void* unused, T4_00909410* out, int type)
{
    if (type != 4)
        return create_other_00909410(unused, out, type);
    out->T4_00909410::T4_00909410();
    return out;
}
