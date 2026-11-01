// from server: 100% by king_originala
struct S {
    char padding[0x18];
    void (__thiscall *setter)(void *, int);
    int adjustment;
    int virtualOffset;

    void set(void *object, int value);
};

void S::set(void *object, int value)
{
    char *base = object ? static_cast<char *>(object) - 0x14 : 0;
    setter(base + 0x134
               + *reinterpret_cast<int *>(
                   *reinterpret_cast<char **>(base + 0x134) + virtualOffset)
               + adjustment,
           value);
}
