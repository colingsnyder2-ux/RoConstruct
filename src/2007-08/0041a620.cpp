// from server: 67% by colin
struct VDHTMLWindow_BoundFuncDesc
{
    void func_0041a620(int, int);
};

extern "C" int __cdecl func_00630d36(int, int, int, int, int);
extern "C" void __cdecl func_00630b9e(int, int);
extern "C" void __stdcall func_0077e710(int);
extern "C" void __stdcall func_00786e04();
extern "C" void __stdcall func_00841e0c();

void VDHTMLWindow_BoundFuncDesc::func_0041a620(int a, int b)
{
    int result = func_00630d36(a, 0, 0x88209c, 0x882bc0, 0);
    if (result == 0)
    {
        func_0077e710(0x786e04);
        func_00630b9e(0x841e0c, 0x786e04);
    }
    int (*fn)(void) = *(int (**)(void))((char*)this + 0x28);
    int offset = *(int*)((char*)this + 0x2c);
    fn();
}
