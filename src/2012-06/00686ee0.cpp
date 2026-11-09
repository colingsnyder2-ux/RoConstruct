// from server: 100% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    if (*(int*)((char*)this + 0x14c) != 0)
    {
        int value = *(int*)((char*)this + 0x148);
        if (value == 4 || value == 1 || value == 3 || value == 5)
            return 1;
    }
    return 0;
}
