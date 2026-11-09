// from server: 100% by atomic.potato
typedef unsigned char byte;

extern "C" void __cdecl Function461190(int, int, int);

struct CNameItem
{
};

void __cdecl f(int a, int b, int c)
{
    if (c != 4)
    {
        Function461190(a, b, c);
        return;
    }

    *(int*)b = 0x00b839b0;
    *((byte*)b + 4) = 0;
    *((byte*)b + 5) = 0;
}
