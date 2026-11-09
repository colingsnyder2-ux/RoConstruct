// from server: 83% by atomic.potato
extern "C" int __cdecl function_00612840(void *, int, int, int);

struct LuaArguments
{
    void *state;
    int function(int, int);
};

int LuaArguments::function(int a, int b)
{
    return function_00612840(*(void **)((char *)this + 0x10), b,
                             *(int *)((char *)this + 0x0c) + a, 1);
}
