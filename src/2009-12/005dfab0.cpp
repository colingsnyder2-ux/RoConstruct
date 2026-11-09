// from server: 54% by atomic.potato
struct S_func_005dfab0
{
    void* pad0;
    void* object;
    int f(void** result, void* arg);
};

typedef void (__thiscall *Callback)(void*, void*, void*);

int S_func_005dfab0::f(void** result, void* arg)
{
    void* object = this->object;
    if (object == 0)
    {
        *result = 0;
        return 0;
    }

    Callback callback = *(Callback *)((char *)*(void **)object + 0x24);
    callback(object, result, arg);
    return (int)result;
}
