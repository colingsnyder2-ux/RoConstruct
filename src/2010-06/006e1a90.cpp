// from server: 86% by atomic.potato
struct S
{
    typedef void (__thiscall *Function)(void *);
    int unused;
    Function function;
    void f(void *);
};

void S::f(void *value)
{
    if (value != 0)
    {
        char *p = (char *)value - 28;
        if (p != 0)
            function((char *)p + 412);
        else
            function(0);
    }
    else
    {
        function(0);
    }
}
