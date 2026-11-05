// from server: 88% by atomic.potato
struct S_func_0084a1b0
{
    struct VTable
    {
        int (__thiscall *func38)(void *, int);
    };

    int field00;
    void *field04;
    int field08;
    int field0c;

    int f(int value);
};

int S_func_0084a1b0::f(int value)
{
    if (field04 != 0 && value != -1)
    {
        int result = ((VTable *)*(void **)field04)->func38(field04, value);
        if (field0c == -1)
            field0c = result;
    }
    return 0;
}
