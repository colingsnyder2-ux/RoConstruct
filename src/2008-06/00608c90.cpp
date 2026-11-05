// from server: 100% by king_originala
typedef void (__thiscall *Setter)(void *, void *);

struct S {
    int reserved[2];
    Setter setter;
    int adjustment;
    int tableOffset;
    void f(void *object, void *value);
};

void S::f(void *object, void *value)
{
    char *base = object ? (char *)object - 20 : 0;
    int offset = *(int *)((char *)*(int **)(base + 308) + tableOffset);
    setter(base + (offset + adjustment) + 308, value);
}
