// from server: 63% by Intel
struct LuaArguments {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
};

extern "C" int __cdecl sub_831FD0(int, int);
extern "C" int __cdecl sub_832480(int, int);
extern "C" int __cdecl sub_832340(int, int, int);
extern "C" int __cdecl sub_831DC0(int, int, int);
extern "C" int __cdecl sub_831B00(int, int);
extern "C" int __cdecl sub_6C1590();
extern "C" void __cdecl sub_521060(int, int);

int __cdecl sub_84D620(int arg0, int arg4, int arg8) {
    int ebx = arg0;
    int esi = arg4;
    int edi = sub_831FD0(ebx, esi);
    if (!edi)
        return 0;
    if (!sub_832480(ebx, esi))
        return 0;
    int eax = *reinterpret_cast<int*>(0xDE13C0);
    sub_832340(eax, 0xFFFFD8F0, esi);
    int result = sub_831DC0(-2, -1, esi);
    if (result) {
        sub_831B00(-3, esi);
        int v = sub_6C1590();
        *reinterpret_cast<int*>(arg8) = v;
        sub_521060(arg8 + 4, edi);
        return 1;
    } else {
        sub_831B00(-3, esi);
        return 0;
    }
}
