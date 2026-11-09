// from server: 100% by colin
struct LuaArguments {
    char pad[12];
    int offset;
    void* L;
    void pushArray(int a, int b);
};

extern "C" void __cdecl sub_53a070(void* L, int index, int count);

void LuaArguments::pushArray(int a, int b)
{
    sub_53a070(L, offset + a, b);
}
