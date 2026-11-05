// from server: 100% by atomic.potato
extern "C" void __cdecl sub_76b1c0(int, int, int);

void f(int a, int b, int c)
{
    if (c != 4)
    {
        sub_76b1c0(a, b, c);
        return;
    }

    *(int *)b = 0x00be4230;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
