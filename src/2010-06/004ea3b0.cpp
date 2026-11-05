// from server: 100% by atomic.potato
extern "C" void __cdecl function_004e6410(int, int, int);

struct S
{
};

void __cdecl f(int a, int b, int c)
{
    if (c != 4)
    {
        function_004e6410(a, b, c);
        return;
    }

    *(unsigned long *)b = 0x00b927f0;
    *((unsigned char *)b + 4) = 0;
    *((unsigned char *)b + 5) = 0;
}
