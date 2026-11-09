// from server: 68% by Intel
extern "C" int __cdecl sub_831fd0(int, int);
extern "C" int __cdecl sub_832480(int, int);
extern "C" int __cdecl sub_832340(int, int, int);
extern "C" int __cdecl sub_831dc0(int, int, int);
extern "C" int __cdecl sub_831b00();
extern "C" int __cdecl sub_6c06d0(int, int);

int *dword_DE13B8;

struct LuaArguments {
    char pad[0x4c];
    int field_0x10;
    int f(int, int);
};

int LuaArguments::f(int a1, int a2) {
    int v3 = sub_831fd0(a1, a2);
    if (!v3)
        return 0;
    if (!sub_832480(a1, a2))
        return 0;
    sub_832340(*dword_DE13B8, -10000, a1);
    int v4 = sub_831dc0(-1, -2, a1);
    if (v4) {
        sub_831b00();
        int v5 = a2;
        sub_6c06d0(v5, v3);
        return 1;
    }
    sub_831b00();
    return 0;
}
