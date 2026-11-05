// from server: 85% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    int result = 0;
    int i = 0;

    while (i < 2)
    {
        int value = (reinterpret_cast<int (__thiscall *)(S *, int)>(
            reinterpret_cast<void **>(*(int *)this)[5]))(this, i);
        if (value != 0)
        {
            if (*(int *)(value + 0x24) == (int)this)
            {
                result = value;
                break;
            }
        }
        ++i;
    }

    return (reinterpret_cast<int (__thiscall *)(S *, int)>(
        reinterpret_cast<void **>(*(int *)this)[3]))(this, 0);
}
