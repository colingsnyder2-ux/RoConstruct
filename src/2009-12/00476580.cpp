// from server: 62% by atomic.potato
extern "C" void __stdcall sub_007f3c02(void *);
extern "C" void __stdcall sub_007f3d28(void *, int);

struct CWebToolbox {
    void f(void *);
    void *field_f8;
};

void CWebToolbox::f(void *)
{
    if (field_f8)
        sub_007f3c02(field_f8);
    sub_007f3d28(this, 0);
}
