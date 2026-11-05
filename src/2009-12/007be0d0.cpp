// from server: 100% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    if (*reinterpret_cast<int *>(this) == 10 &&
        *reinterpret_cast<int *>(reinterpret_cast<char *>(this) + 8) == 12)
        return 1;
    return 0;
}
