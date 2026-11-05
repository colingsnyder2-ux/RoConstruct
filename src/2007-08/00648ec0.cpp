// from server: 35% by colin
// roc 2007-08 00648ec0 196 bytes CXTPCommandBar

extern "C" int __cdecl sub_62FF02(void*);
extern "C" void __cdecl sub_62FF20();
extern "C" int __cdecl sub_63044E(int);
extern "C" void __cdecl sub_648F8A();

struct CXTPCommandBar {
    int sub_648E90(void*);
    int method(int, int, int);
};

int CXTPCommandBar::method(int a, int b, int c)
{
    int local20 = 0;
    int* p = (int*)sub_62FF02(&local20);
    int v = sub_63044E(p[0x9c / 4]);
    if (v == 0)
        return 0;

    int local28;
    this->sub_648E90(&local28);

    int fn = *(int*)((char*)this + 0x54);
    if (fn == 0)
        sub_62FF20();

    int result = ((int (__stdcall*)(int, int, int))fn)(a, b, c);
    sub_648F8A();
    return result;
}
