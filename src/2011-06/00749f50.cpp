// from server: 74% by atomic.potato
struct S_func_00749f50 {
};

int __cdecl f(int *a, int *b, int *c, int *d)
{
    if (a[0] && *((int *)((char *)b + a[0] * 4 + 0x120)) == 1)
        return 1;
    if (d[0] && *((int *)((char *)c + d[0] * 4 + 0x120)) == 1)
        return 1;
    return 0;
}
