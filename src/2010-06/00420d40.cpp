// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00420d40 {
    T4_00420d40();
    virtual void f_00420d40();
    char m_a;
    char m_b;
};
T4_00420d40::T4_00420d40() : m_a(0), m_b(0) {}
extern "C" void* create_other_00420d40(void*, void*, int);
void* create_00420d40(void* unused, T4_00420d40* out, int type)
{
    if (type != 4)
        return create_other_00420d40(unused, out, type);
    out->T4_00420d40::T4_00420d40();
    return out;
}
