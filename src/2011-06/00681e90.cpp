// from server: 100% by atomic.potato
extern "C" void __cdecl sub_681bb0(int, int, int);

struct S
{
};

void __cdecl f(int a, int b, int c)
{
    if (c != 4)
    {
        sub_681bb0(a, b, c);
        return;
    }

    *(int*)b = 0x00c5ca98;
    *((unsigned char*)b + 4) = 0;
    *((unsigned char*)b + 5) = 0;
}
