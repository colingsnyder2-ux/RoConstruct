// from server: 48% by atomic.potato
extern "C" void __stdcall func_007f3e30(void *);
extern "C" void __stdcall func_007f3c02(void *);

struct CWebToolbox
{
    void f();
    void *field_f8;
};

void CWebToolbox::f()
{
    func_007f3e30(this);
    if (field_f8)
        func_007f3c02(field_f8);
}
