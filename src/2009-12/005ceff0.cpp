// from server: 100% by atomic.potato
extern "C" void __cdecl sub_5cc960(void *, void *, int);

struct S
{
};

void __cdecl f(void *a, void *b, int c)
{
    if (c != 4)
    {
        sub_5cc960(a, b, c);
        return;
    }

    *(unsigned long *)b = 0x00b25e20;
    *((unsigned char *)b + 4) = 0;
    *((unsigned char *)b + 5) = 0;
}
