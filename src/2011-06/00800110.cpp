// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00800110 {
    T4_00800110();
    virtual void f_00800110();
    char m_a;
    char m_b;
};
T4_00800110::T4_00800110() : m_a(0), m_b(0) {}
extern "C" void* create_other_00800110(void*, void*, int);
void* create_00800110(void* unused, T4_00800110* out, int type)
{
    if (type != 4)
        return create_other_00800110(unused, out, type);
    out->T4_00800110::T4_00800110();
    return out;
}
