// from server: 100% by atomic.potato
extern "C" void __cdecl Function6217F0(int, int, int);

struct S
{
};

void __cdecl f(int a, int b, int c)
{
    if (c != 4)
    {
        Function6217F0(a, b, c);
        return;
    }

    *(int *)b = 0x00bb0d18;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
