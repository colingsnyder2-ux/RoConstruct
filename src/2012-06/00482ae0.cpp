// from server: 40% by atomic.potato
struct BoundVerb
{
    void f(int);
};

extern void __stdcall G1_func_0040f780(int);

void BoundVerb::f(int)
{
    int value = *reinterpret_cast<int *>(reinterpret_cast<char *>(this) + 0x10);
    if (value != 0 && (*reinterpret_cast<int *>(reinterpret_cast<char *>(this) + 0x10) & 0x59a790) != 0)
        G1_func_0040f780(*reinterpret_cast<int *>(reinterpret_cast<char *>(this) + 8));
}
