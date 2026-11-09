// from server: 100% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    int *a = *(int **)((char *)this - 0x128);
    int *b = *(int **)((char *)a + 0x108);
    return *(int *)((char *)b + 0x30);
}
