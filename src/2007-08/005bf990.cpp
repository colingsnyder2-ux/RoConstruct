// from server: 64% by colin
struct LuaArguments {
    int m_L;
    int m_offset;
    void f(int a1);
};

extern "C" int __cdecl sub_630d36(int, int, int, int, int);
extern "C" void __cdecl sub_630b9e(int, int);
extern "C" void __stdcall sub_77e710(int);
extern "C" void __stdcall sub_77e710_bad_cast(int);

void LuaArguments::f(int a1)
{
    int v = sub_630d36(m_L, 0, 0x887174, 0x887c60, 0);
    if (v == 0) {
        sub_77e710(0x786e04);
        sub_630b9e(0x841e0c, (int)&v);
    }
    int* p = (int*)(v + 0x18);
    int* obj = (int*)*p;
    int* vtbl = (int*)*obj;
    int fn = vtbl[2];
    ((void (__thiscall*)(int*, int, int))fn)(obj, m_offset, a1);
}
