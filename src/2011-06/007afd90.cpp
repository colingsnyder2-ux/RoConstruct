// from server: 75% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    int i = 0;
    int result = 0;

    do
    {
        void **vtable = *(void ***)this;
        result = ((int (__thiscall *)(S *, int))vtable[5])(this, 0);
        if (result != 0)
        {
            if (*(S **)(result + 40) == this)
                break;
        }
        ++i;
    } while (i < 2);

    if (i == 2)
        result = 0;

    void **vtable = *(void ***)this;
    return ((int (__thiscall *)(S *, int))vtable[3])(this, result);
}
