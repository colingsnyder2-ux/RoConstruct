// from server: 100% by atomic.potato
extern "C" void __cdecl sub_4599c0(int, int*, int);

void f(int a, int* b, int c)
{
    if (c != 4)
    {
        sub_4599c0(a, b, c);
        return;
    }
    *b = 0x00B82DF8;
    ((char*)b)[4] = 0;
    ((char*)b)[5] = 0;
}
