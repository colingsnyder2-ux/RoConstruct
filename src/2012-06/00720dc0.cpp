// from server: 82% by atomic.potato
extern "C" void __cdecl target_71f400(int);

struct S
{
    void __cdecl f(int, int);
};

void S::f(int a, int b)
{
    if (b != 4)
    {
        target_71f400(b);
        return;
    }

    *(int *)a = 0x00DADDC8;
    *((char *)a + 4) = 0;
    *((char *)a + 5) = 0;
}
