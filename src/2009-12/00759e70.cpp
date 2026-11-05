// from server: 72% by atomic.potato
extern "C" void __cdecl Function0040C080(int);

struct S
{
    void Set(int);
};

void S::Set(int value)
{
    if (value != *reinterpret_cast<int *>(reinterpret_cast<char *>(this) + 0x1d4))
    {
        *reinterpret_cast<int *>(reinterpret_cast<char *>(this) + 0x1d4) = value;
        Function0040C080(0xB9769C);
    }
}
