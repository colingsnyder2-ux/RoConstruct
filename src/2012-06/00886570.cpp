// from server: 58% by atomic.potato
struct S
{
};

int __cdecl f(int, int value, int result)
{
    if (result != 4)
    {
        *reinterpret_cast<int*>(value) = 0x00de8498;
        reinterpret_cast<char*>(value)[4] = 0;
        reinterpret_cast<char*>(value)[5] = 0;
        return 0;
    }
    return 0;
}
