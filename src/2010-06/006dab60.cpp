// from server: 55% by atomic.potato
struct S
{
    int f(void *);
    int (**vtable)(void *);
    int offset;
    int index;
};

int S::f(void *p)
{
    char *base = p ? static_cast<char *>(p) - 28 : 0;
    int *table = *reinterpret_cast<int **>(base + 152);
    void *target = reinterpret_cast<char *>(table[index]) + offset;
    return (*vtable)(reinterpret_cast<char *>(target) + reinterpret_cast<int>(base) + 152);
}
