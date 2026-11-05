// from server: 100% by atomic.potato
struct S
{
    int Get();
    int pad[2466];
    int value;
};

int S::Get()
{
    int p = pad[2466];
    if (p)
        return *(int *)(p + 0x15c);
    return 0;
}
