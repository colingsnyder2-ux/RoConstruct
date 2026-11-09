// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00797340 {
    T4_00797340();
    virtual void f_00797340();
    char m_a;
    char m_b;
};
T4_00797340::T4_00797340() : m_a(0), m_b(0) {}
extern "C" void* create_other_00797340(void*, void*, int);
void* create_00797340(void* unused, T4_00797340* out, int type)
{
    if (type != 4)
        return create_other_00797340(unused, out, type);
    out->T4_00797340::T4_00797340();
    return out;
}
