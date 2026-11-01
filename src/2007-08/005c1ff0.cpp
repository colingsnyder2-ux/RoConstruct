// from server: 100% by colin
struct LuaArguments {
    int construct(int a, int b);
};

extern "C" int* __cdecl sub_5BE5B0(int, int);
extern "C" void __cdecl sub_5BDE00(int, int, int);
extern "C" void __cdecl sub_5BE160(int, int);

extern int dword_8ABE7C;

int __cdecl LuaArguments_construct(int a, int b)
{
    int* p = sub_5BE5B0(a, 4);
    if (p != 0)
        *p = 0x17;
    sub_5BDE00(a, -10000, dword_8ABE7C);
    sub_5BE160(a, -2);
    return 1;
}
