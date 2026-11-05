// from server: 100% by atomic.potato
extern "C" void __cdecl sub_6A2C80(int, int, int);

struct S
{
};

void __cdecl f(int a, int b, int c)
{
    if (c != 4)
    {
        sub_6A2C80(a, b, c);
        return;
    }

    *(int*)b = 0xD9E9E8;
    *((char*)b + 4) = 0;
    *((char*)b + 5) = 0;
}
