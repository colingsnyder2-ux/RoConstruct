// from server: 52% by atomic.potato
extern "C" void __cdecl function_007cf120();

struct S
{
    void __cdecl f(int, int);
};

void S::f(int a, int b)
{
    if (b == 4)
    {
        *(int*)a = 0x00dcbc28;
        *((char*)a + 4) = 0;
        *((char*)a + 5) = 0;
    }
    else
    {
        function_007cf120();
    }
}
