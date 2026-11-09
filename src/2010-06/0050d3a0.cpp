// from server: 100% by atomic.potato
extern "C" void __cdecl sub_50c0c0(int, int, int);

void f(int a, int b, int c)
{
    if (c != 4)
    {
        sub_50c0c0(a, b, c);
        return;
    }

    *(int*)b = 0x00b950b0;
    *((char*)b + 4) = 0;
    *((char*)b + 5) = 0;
}
