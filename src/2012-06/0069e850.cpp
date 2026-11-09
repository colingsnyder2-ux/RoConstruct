// from server: 60% by atomic.potato
struct S
{
};

void __cdecl f(int a, int b, int c, int d)
{
    if (c != 4)
        return;

    *(int *)b = 0x00d9dc50;
    *((unsigned char *)b + 4) = 0;
    *((unsigned char *)b + 5) = 0;
}
