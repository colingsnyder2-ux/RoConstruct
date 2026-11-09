// from server: 100% by atomic.potato
struct lua_exception {
    char pad[0xc];
    void* field_c;
    void func();
};

extern "C" void __cdecl func_762760(void*, int, int);

void lua_exception::func()
{
    func_762760(field_c, -1, 0);
}
