// from server: 100% by atomic.potato
extern "C" void __cdecl target_006988d0(int, int, int);

struct S
{
};

void __cdecl f(int a, int b, int c)
{
    if (c != 4)
    {
        target_006988d0(a, b, c);
        return;
    }

    *(int *)b = 0x00c63be0;
    *((unsigned char *)b + 4) = 0;
    *((unsigned char *)b + 5) = 0;
}
