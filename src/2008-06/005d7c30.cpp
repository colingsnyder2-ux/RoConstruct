// from server: 100% by king_originala
struct S
{
    char padding[0x18];
    void (__thiscall *setter)(void *, float);
    int adjustment;
    int virtualOffset;

    void f(void *object, const float *value);
};

void S::f(void *object, const float *value)
{
    char *base = object ? static_cast<char *>(object) - 0x14 : 0;
    float argument = *value;
    int offset = *reinterpret_cast<int *>(
        *reinterpret_cast<char **>(base + 0x150) + virtualOffset);
    setter(base + 0x150 + offset + adjustment, argument);
}
