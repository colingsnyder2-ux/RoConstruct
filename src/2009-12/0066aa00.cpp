// from server: 100% by atomic.potato
extern "C" void __cdecl target_669b50(int, int, int);

struct S
{
};

void __cdecl f(int a, int b, int c)
{
    if (c != 4)
    {
        target_669b50(a, b, c);
        return;
    }

    *(int*)b = 0x00b33a08;
    *((unsigned char*)b + 4) = 0;
    *((unsigned char*)b + 5) = 0;
}
