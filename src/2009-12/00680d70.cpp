// from server: 79% by atomic.potato
struct Script
{
    int f();
};

int Script::f()
{
    if (*(unsigned char *)((char *)this + 0x9c))
    {
        if (!*(unsigned char *)((char *)this + 0x9d))
            return 0;
    }
    return 1;
}
