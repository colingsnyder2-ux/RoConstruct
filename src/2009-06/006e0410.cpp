// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_006e0410 {
    T4_006e0410();
    virtual void f_006e0410();
    char m_a;
    char m_b;
};
T4_006e0410::T4_006e0410() : m_a(0), m_b(0) {}
extern "C" void* create_other_006e0410(void*, void*, int);
void* create_006e0410(void* unused, T4_006e0410* out, int type)
{
    if (type != 4)
        return create_other_006e0410(unused, out, type);
    out->T4_006e0410::T4_006e0410();
    return out;
}
