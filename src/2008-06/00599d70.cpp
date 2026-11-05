// from server: 100% by king_originala
typedef void (__thiscall *Setter)(void *, float);

struct S {
    char padding[0x18];
    Setter setter;
    int adjustment;
    int tableOffset;

    void f(void *object, const float *value);
};

void S::f(void *object, const float *value)
{
    char *base = object ? (char *)object - 0x14 : 0;
    int offset = tableOffset;
    setter(base + 0x134 +
               *(int *)(*(char **)(base + 0x134) + offset) +
               adjustment,
           *value);
}
