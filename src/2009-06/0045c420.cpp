// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
struct T4_0045c420 {
    T4_0045c420();
    virtual void f_0045c420();
    char m_a;
    char m_b;
};
T4_0045c420::T4_0045c420() : m_a(0), m_b(0) {}
extern "C" void* create_other_0045c420(void*, void*, int);
void* create_0045c420(void* unused, T4_0045c420* out, int type)
{
    if (type != 4)
        return create_other_0045c420(unused, out, type);
    out->T4_0045c420::T4_0045c420();
    return out;
}
