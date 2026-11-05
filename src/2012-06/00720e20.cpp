// from server: 91% by atomic.potato
extern "C" void __cdecl sub_71f4e0(int, int, int);

struct S
{
};

void __cdecl f(int a, int b, int c)
{
    if (b != 4)
    {
        sub_71f4e0(a, b, c);
        return;
    }

    *(int*)a = 0x00DADEC8;
    *((char*)a + 4) = 0;
    *((char*)a + 5) = 0;
}
