// from server: 100% by king_originala
typedef void (__thiscall *Setter)(void *, int);

struct S {
    char padding[24];
    Setter setter;
    int adjustment;
    int virtualOffset;
    void f(void *object, int value);
};

void S::f(void *object, int value)
{
    char *base = object ? (char *)object - 20 : 0;
    setter(base + 448 +
           (*(int *)((char *)*(int **)(base + 448) + virtualOffset)
            + adjustment), value);
}
