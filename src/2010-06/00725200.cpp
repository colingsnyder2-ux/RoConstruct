// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00725200 {
    T4_00725200();
    virtual void f_00725200();
    char m_a;
    char m_b;
};
T4_00725200::T4_00725200() : m_a(0), m_b(0) {}
extern "C" void* create_other_00725200(void*, void*, int);
void* create_00725200(void* unused, T4_00725200* out, int type)
{
    if (type != 4)
        return create_other_00725200(unused, out, type);
    out->T4_00725200::T4_00725200();
    return out;
}
