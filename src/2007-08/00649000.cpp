// from server: 41% by colin
struct CXTPCommandBar {
    int field_9c;
    int sub_648FC0(void*);
    int sub_649000(int, int, int);
};

extern "C" int __cdecl sub_62FF02(void*);
extern "C" int __cdecl sub_63044E(int);
extern "C" void __cdecl sub_62FF20(void);
extern "C" void __cdecl sub_6490CD(void);

int CXTPCommandBar::sub_649000(int a1, int a2, int a3)
{
    int local_20;
    int local_24;
    int local_28;
    int result;

    local_20 = 0;
    int v = sub_62FF02(&local_20);
    int v2 = sub_63044E(*(int*)(v + 0x9c));
    local_24 = v2;
    if (v2 != 0)
        return 0;

    sub_648FC0(&local_28);

    int f = *(int*)((char*)this + 0x9c);
    if (f == 0)
        sub_62FF20();

    result = ((int (__stdcall*)(int, int, int))f)(a1, a2, a3);
    sub_6490CD();
    return result;
}
