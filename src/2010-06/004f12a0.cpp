// from server: 100% by atomic.potato
extern "C" void __cdecl sub_4eda70(int, void *, int);

struct S
{
};

void __cdecl f(int a, void *p, int b)
{
    if (b != 4)
    {
        sub_4eda70(a, p, b);
        return;
    }

    *(int *)p = 0xb92e10;
    *((char *)p + 4) = 0;
    *((char *)p + 5) = 0;
}
