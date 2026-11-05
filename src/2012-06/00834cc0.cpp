// from server: 100% by tester
extern "C" int __cdecl sub_6b8d80(int);

struct LuaArguments {
    char pad[0x4c];
    int field_0x10;
    int f();
};

int LuaArguments::f() {
    return sub_6b8d80(field_0x10) - 1;
}
