// from server: 93% by atomic.potato
struct LuaArguments
{
    int padding0C;
    int padding10;
    int field0C;
    int field10;
    void f(int, int);
};

extern "C" void __cdecl G1_func_0077c500(int, int, int, int);

void LuaArguments::f(int a, int b)
{
    G1_func_0077c500(field10, field0C + a, b, 1);
}
