// from server: 100% by atomic.potato
extern "C" void __cdecl Function526DC0(int, int, int);

struct S
{
};

void __cdecl f(int a, int b, int c)
{
    if (c != 4)
    {
        Function526DC0(a, b, c);
        return;
    }

    *(long*)b = 0x00B1AB10;
    *((char*)b + 4) = 0;
    *((char*)b + 5) = 0;
}
