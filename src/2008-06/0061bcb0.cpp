// from server: 100% by atomic.potato
extern "C" void __cdecl Function005ad380(int, int, int, int);

struct LuaArguments
{
    void f(int, int);
};

void LuaArguments::f(int a, int b)
{
    Function005ad380(*(int*)((char*)this + 0x10), *(int*)((char*)this + 0x0c) + a, b, 1);
}
