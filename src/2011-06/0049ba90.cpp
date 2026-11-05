// from server: 78% by atomic.potato
extern "C" void __cdecl sub_0080b018(int);

extern "C" void __cdecl sub_0080a400();

struct CWebToolbox
{
    void f(int);
    int field_f8;
};

void CWebToolbox::f(int value)
{
    sub_0080b018(value);
    if (*(int *)((char *)this + 0xf8))
        sub_0080a400();
}
