// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_004b0420 {
    T4_004b0420();
    virtual void f_004b0420();
    char m_a;
    char m_b;
};
T4_004b0420::T4_004b0420() : m_a(0), m_b(0) {}
extern "C" void* create_other_004b0420(void*, void*, int);
void* create_004b0420(void* unused, T4_004b0420* out, int type)
{
    if (type != 4)
        return create_other_004b0420(unused, out, type);
    out->T4_004b0420::T4_004b0420();
    return out;
}
