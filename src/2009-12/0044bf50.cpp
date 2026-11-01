// from server: 80% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    int **a = *(int ***)(this + 0x58);
    int *b = *(int **)((char *)a + 0x20);
    int (**vtable)(int, int) = *(int (***)(int, int))b;
    return vtable[0x22](0, 1);
}
