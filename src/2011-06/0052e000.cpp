// from server: 77% by atomic.potato
struct S
{
    int Get();
};

int S::Get()
{
    int result = *reinterpret_cast<int *>(reinterpret_cast<char *>(this) + 0xbd8);
    volatile int unused = *reinterpret_cast<int *>(reinterpret_cast<char *>(this) + 0xbdc);
    return result;
}
