// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00470150 {
    T4_00470150();
    virtual void f_00470150();
    char m_a;
    char m_b;
};
T4_00470150::T4_00470150() : m_a(0), m_b(0) {}
extern "C" void* create_other_00470150(void*, void*, int);
void* create_00470150(void* unused, T4_00470150* out, int type)
{
    if (type != 4)
        return create_other_00470150(unused, out, type);
    out->T4_00470150::T4_00470150();
    return out;
}
