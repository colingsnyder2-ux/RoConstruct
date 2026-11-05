// from server: 31% by atomic.potato
struct S_func_00547120
{
    void* m_value;
    void* m_object;
    int f(void** result, void* argument);
};

int S_func_00547120::f(void** result, void* argument)
{
    void* value = m_object;
    if (value == 0)
    {
        *result = value;
        return 0;
    }

    typedef int (__thiscall *Function)(void*, void*, void*);
    Function function = *(Function*)(((char*)*(void**)value) + 0x24);
    function(value, result, argument);
    return 0;
}
