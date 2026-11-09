// from server: 37% by atomic.potato
struct LuaArguments
{
    void* func(int);
};

void* LuaArguments::func(int value)
{
    func(0);
    return (void*)value;
}
