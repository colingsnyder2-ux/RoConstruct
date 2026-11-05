// from server: 100% by atomic.potato
extern "C" void __cdecl sub_53D410(int, int, int);

void f(int a, int b, int c)
{
    if (c != 4)
    {
        sub_53D410(a, b, c);
        return;
    }

    *(unsigned long*)b = 0x00B1DF88;
    *((unsigned char*)b + 4) = 0;
    *((unsigned char*)b + 5) = 0;
}
