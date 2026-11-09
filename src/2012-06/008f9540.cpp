// from server: 63% by atomic.potato
struct S
{
};

void __cdecl f(void *a, int b, int c)
{
    if (c == 4)
        return;
    *(int *)b = 0xdfddc0;
    *((char *)b + 4) = 0;
    *((char *)b + 5) = 0;
}
