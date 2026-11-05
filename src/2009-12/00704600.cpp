// from server: 100% by atomic.potato
struct S
{
};

extern "C" void __cdecl g(int, int, int);

void __cdecl f(int a, int b, int c)
{
    if (c != 4)
    {
        g(a, b, c);
        return;
    }

    *(int*)b = 0xb49060;
    *(char*)(b + 4) = 0;
    *(char*)(b + 5) = 0;
}
