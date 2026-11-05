// from server: 100% by atomic.potato
extern "C" void target(int, int, int, int);

struct S
{
};

void __cdecl f(int a, int b, int c, int d)
{
    if (c != 4)
    {
        target(a, b, c, d);
        return;
    }

    *((unsigned int*)b) = 0xc46a60;
    *((unsigned char*)b + 4) = 0;
    *((unsigned char*)b + 5) = 0;
}
