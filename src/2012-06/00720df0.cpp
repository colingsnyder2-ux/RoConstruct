// from server: 51% by atomic.potato
extern "C" void __cdecl f_71f470(int, int, int);

struct S
{
};

void __cdecl f(int a, int b)
{
    if (a == 4)
    {
        *(int*)b = 0x00dade50;
        *((char*)b + 4) = 0;
        *((char*)b + 5) = 0;
    }
    else
    {
        f_71f470(0, b, a);
    }
}
