// from server: 96% by atomic.potato
struct S
{
};

int * __cdecl f(int *p)
{
    int *ecx = p ? p + 0x1c : 0;
    int **edx = (int **)*ecx;
    int **eax = edx;

    while (*eax != ecx)
        eax = (int **)*eax;

    *eax = (int *)edx;
    return (int *)eax;
}
