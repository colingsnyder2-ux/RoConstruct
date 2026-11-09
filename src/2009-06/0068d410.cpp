// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_0068d410 {
    T4_0068d410();
    virtual void f_0068d410();
    char m_a;
    char m_b;
};
T4_0068d410::T4_0068d410() : m_a(0), m_b(0) {}
extern "C" void* create_other_0068d410(void*, void*, int);
void* create_0068d410(void* unused, T4_0068d410* out, int type)
{
    if (type != 4)
        return create_other_0068d410(unused, out, type);
    out->T4_0068d410::T4_0068d410();
    return out;
}
