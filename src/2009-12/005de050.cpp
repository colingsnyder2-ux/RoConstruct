// from server: 100% by atomic.potato
extern "C" void __cdecl sub_005dddb0(int, int, int);

struct S_func_005de050
{
};

void __cdecl f(int a, int b, int c)
{
    if (c != 4)
        sub_005dddb0(a, b, c);
    else
    {
        *(int*)b = 0x00b264e8;
        *((unsigned char*)b + 4) = 0;
        *((unsigned char*)b + 5) = 0;
    }
}
