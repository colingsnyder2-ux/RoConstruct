// from server: 58% by atomic.potato
struct S
{
};

void __cdecl f(int a, int b, int c)
{
    if (c != 4)
        f(a, b, c);
    *(int*)b = 0x00DE7118;
    *((unsigned char*)b + 4) = 0;
    *((unsigned char*)b + 5) = 0;
}
