// from server: 47% by atomic.potato
struct S
{
};

void __cdecl f(int, int *p, int a)
{
    if (a != 4)
        return;

    *p = 0xdd4708;
    p[1] = 0;
    p[2] = 0;
}
