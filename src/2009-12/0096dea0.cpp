// from server: 23% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    return *reinterpret_cast<int *>(reinterpret_cast<char *>(this) + 0x40);
}
