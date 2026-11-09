// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_004f1300 {
    T4_004f1300();
    virtual void f_004f1300();
    char m_a;
    char m_b;
};
T4_004f1300::T4_004f1300() : m_a(0), m_b(0) {}
extern "C" void* create_other_004f1300(void*, void*, int);
void* create_004f1300(void* unused, T4_004f1300* out, int type)
{
    if (type != 4)
        return create_other_004f1300(unused, out, type);
    out->T4_004f1300::T4_004f1300();
    return out;
}
