// from server: 93% by atomic.potato
struct S_007046f0
{
    void __cdecl Invoke(float, int);
};

void S_007046f0::Invoke(float value, int arg)
{
    if (*reinterpret_cast<int *>(reinterpret_cast<char *>(this) + 0x10) != 0)
        reinterpret_cast<int (__thiscall *)(void *, int, float)>(
            *reinterpret_cast<int **>(
                *reinterpret_cast<int **>(reinterpret_cast<char *>(this) + 8)))(
            reinterpret_cast<char *>(this) + 8, arg, value);
}
