// from server: 100% by atomic.potato
extern "C" void dispatch(int, int, int);

struct S
{
};

void __cdecl f(int a, int b, int c)
{
    if (c != 4)
    {
        dispatch(a, b, c);
    }
    else
    {
        *(int*)b = 0xb10c90;
        *(unsigned char*)(b + 4) = 0;
        *(unsigned char*)(b + 5) = 0;
    }
}
