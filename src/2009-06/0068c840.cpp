// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_0068c840 {
    T4_0068c840();
    virtual void f_0068c840();
    char m_a;
    char m_b;
};
T4_0068c840::T4_0068c840() : m_a(0), m_b(0) {}
extern "C" void* create_other_0068c840(void*, void*, int);
void* create_0068c840(void* unused, T4_0068c840* out, int type)
{
    if (type != 4)
        return create_other_0068c840(unused, out, type);
    out->T4_0068c840::T4_0068c840();
    return out;
}
