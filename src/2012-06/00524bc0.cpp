// from server: 69% by atomic.potato
struct S
{
};

void __cdecl f(int a, int b)
{
    if (a == 4)
    {
        static void (*p)(int) = (void (*)(int))0x00521bb0;
        p(a);
        return;
    }

    *(int*)b = 0x00d7bf28;
    *((unsigned char*)b + 4) = 0;
    *((unsigned char*)b + 5) = 0;
}
