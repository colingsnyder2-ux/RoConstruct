// from server: 83% by colin
struct CWebToolbox
{
    void sub_466910(int a, int b, int c);
};

extern "C" void __stdcall sub_63023E();
extern "C" void __stdcall sub_630004();

void CWebToolbox::sub_466910(int a, int b, int c)
{
    sub_63023E();
    if (*(int*)((char*)this + 0xf4) != 0)
    {
        sub_630004();
    }
}
