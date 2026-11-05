// from server: 100% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    int value = *reinterpret_cast<int *>(reinterpret_cast<char *>(this) + 0x1ec);
    return value == 0 || value == 2;
}
