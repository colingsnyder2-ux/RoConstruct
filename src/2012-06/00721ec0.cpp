// from server: 47% by atomic.potato
struct S
{
};

int __cdecl f(void *a)
{
    int *p = *(int **)((char *)a + 0x10);
    int v = *(int *)((char *)a + 8);
    return *(int *)((char *)a + 4) + *(int *)((char *)p + 0x84 + v) + (int)p + 0x84;
}
