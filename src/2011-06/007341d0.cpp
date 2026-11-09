// from server: 100% by atomic.potato
extern "C" void __cdecl sub_733c70(int, int, int);

struct S
{
};

void __cdecl f(int a, int b, int c)
{
    if (c != 4)
    {
        sub_733c70(a, b, c);
        return;
    }

    *(int*)b = 0x00c89028;
    *((char*)b + 4) = 0;
    *((char*)b + 5) = 0;
}
