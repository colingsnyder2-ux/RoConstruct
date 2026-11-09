// from server: 53% by atomic.potato
struct LuaArguments
{
    void f(void*);
};

extern void G1_func_0084e400(void*, void*, void*);

void LuaArguments::f(void* p)
{
    G1_func_0084e400((char*)this + 4, p, 0);
}
