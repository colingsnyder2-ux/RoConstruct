// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_005aa110 {
    T4_005aa110();
    virtual void f_005aa110();
    char m_a;
    char m_b;
};
T4_005aa110::T4_005aa110() : m_a(0), m_b(0) {}
extern "C" void* create_other_005aa110(void*, void*, int);
void* create_005aa110(void* unused, T4_005aa110* out, int type)
{
    if (type != 4)
        return create_other_005aa110(unused, out, type);
    out->T4_005aa110::T4_005aa110();
    return out;
}
