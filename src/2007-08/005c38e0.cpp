// from server: 100% by colin
struct LuaArguments {
    int construct(int a1);
};

extern int g_luaState;

int __cdecl sub_5BF240(int a1, int a2, int a3);

struct Helper {
    void method();
};

int __cdecl LuaArguments_construct(int a1)
{
    int r = sub_5BF240(a1, 1, g_luaState);
    ((Helper*)r)->method();
    return 0;
}
