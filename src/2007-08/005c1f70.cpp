// from server: 100% by colin
struct LuaArguments {
    int construct(void* L);
};

extern "C" void* __cdecl sub_5be5b0(void* p, unsigned int size);
extern "C" void __cdecl sub_5bde00(void* L, int offset, void* f);
extern "C" void __cdecl sub_5be160(void* L, int idx);

extern void* g_8abe7c;

int __cdecl LuaArguments_construct(void* L)
{
    void* p = sub_5be5b0(L, 4);
    if (p)
        *(int*)p = 0x18;
    sub_5bde00(L, -10000, g_8abe7c);
    sub_5be160(L, -2);
    return 1;
}
