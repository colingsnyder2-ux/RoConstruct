// from server: 100% by atomic.potato
extern "C" void __cdecl sub_4c22f0(int, int, int);

void f(int, int, int);

void f(int a, int b, int c)
{
    if (c != 4)
    {
        sub_4c22f0(a, b, c);
    }
    else
    {
        *(int*)b = 0x00b10b58;
        *((unsigned char*)b + 4) = 0;
        *((unsigned char*)b + 5) = 0;
    }
}
