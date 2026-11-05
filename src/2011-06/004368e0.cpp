// from server: 100% by atomic.potato
extern "C" void __cdecl Dispatch(int, int, int);

struct S
{
};

void __cdecl f(int a, int b, int c)
{
    if (c != 4)
    {
        Dispatch(a, b, c);
        return;
    }

    *(int *)b = 0x00c0d8b8;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
