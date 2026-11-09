// from server: 75% by atomic.potato
struct S
{
};

int __cdecl f(int *a, int **b)
{
    *b = a ? a + 0x1c : 0;
    return 0;
}
