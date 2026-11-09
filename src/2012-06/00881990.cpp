// from server: 82% by atomic.potato
extern "C" void __cdecl sub_8807F0(int);

struct S
{
    void __cdecl f(int, int);
};

void S::f(int a, int b)
{
    if (b != 4)
    {
        sub_8807F0(b);
        return;
    }

    *(int*)a = 0xDE7E20;
    *((char*)a + 4) = 0;
    *((char*)a + 5) = 0;
}
