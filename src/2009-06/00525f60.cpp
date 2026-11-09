// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_00525f60 {
    T4_00525f60();
    virtual void f_00525f60();
    char m_a;
    char m_b;
};
T4_00525f60::T4_00525f60() : m_a(0), m_b(0) {}
extern "C" void* create_other_00525f60(void*, void*, int);
void* create_00525f60(void* unused, T4_00525f60* out, int type)
{
    if (type != 4)
        return create_other_00525f60(unused, out, type);
    out->T4_00525f60::T4_00525f60();
    return out;
}
