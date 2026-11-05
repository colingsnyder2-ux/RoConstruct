// from server: 100% by atomic.potato
struct S_func_007aaa90
{
    struct Result
    {
        char pad0[60];
    };

    struct VTable
    {
        void* pad0[4];
        Result* (__thiscall *f)(S_func_007aaa90*, int);
    };

    VTable* vtable;
    int f();
};

int S_func_007aaa90::f()
{
    Result* result = vtable->f(this, 0);
    if (result->pad0[60] != 0)
    {
        result = vtable->f(this, 1);
        if (result->pad0[60] != 0)
            return 1;
    }
    return 0;
}
