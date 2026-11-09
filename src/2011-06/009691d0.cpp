// from server: 30% by atomic.potato
struct S
{
    int f();
    char pad[0x68];
    int value;
};

int S::f()
{
    unsigned int i = 0;
    do
    {
        int* p = (int*)((char*)value + i);
        if (p[1] || p[3] || p[5] || p[7])
            return 0;
        i += 0x20;
    } while (i < 0x10000);
    return 0;
}
