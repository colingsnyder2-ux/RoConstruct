// from server: 100% by atomic.potato
extern "C" void __cdecl sub_4CA360(int, int, int, int);

void __cdecl sub_4CB170(int a, int b, int c)
{
    if (c != 3)
    {
        char zero = 0;
        sub_4CA360(a, b, c, *(int*)&zero);
        return;
    }
    *(int*)b = 0x93cd10;
}
