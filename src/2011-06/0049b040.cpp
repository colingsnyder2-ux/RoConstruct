// from server: 71% by atomic.potato
struct S_func_0049b040
{
    char pad0[4];
    unsigned char flag;
    char pad1[263];
    void *callback;

    int f();
};

int S_func_0049b040::f()
{
    if (flag)
    {
        void **vtable = *(void ***)callback;
        unsigned char (__thiscall *method)(void *) =
            (unsigned char (__thiscall *)(void *))vtable[3];
        if (method(callback))
            return 0;
        return 1;
    }
    return 0;
}
