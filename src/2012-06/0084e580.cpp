// from server: 42% by atomic.potato
struct LuaArguments
{
    void f(int);
    void g(int);
};

void LuaArguments::f(int value)
{
    g(0);
}
