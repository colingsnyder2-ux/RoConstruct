// from server: 100% by atomic.potato
extern "C" int __cdecl universalTool(void *, void *, int);

struct LuaArguments
{
};

int __cdecl f(void *object, int value)
{
    int result = universalTool(object, (void *)value, 0);
    if (!result)
        result = *(int *)0x00be2a74;
    return result;
}
