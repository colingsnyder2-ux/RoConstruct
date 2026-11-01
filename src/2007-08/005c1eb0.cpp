// from server: 100% by colin
struct LuaArguments {
    int construct(int a, int b, int c);
};

extern "C" int __cdecl sub_5be5b0(int, int);
extern "C" int __cdecl sub_5bde00(int, int, int);
extern "C" int __cdecl sub_5be160(int, int);

extern int dword_8ABE7C;

int __cdecl LuaArguments_construct(int a, int b, int c)
{
    int* p = (int*)sub_5be5b0(a, 4);
    if (p != 0)
        *p = 0xC2;
    sub_5bde00(a, -10000, dword_8ABE7C);
    sub_5be160(a, -2);
    return 1;
}
