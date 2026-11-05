// from server: 85% by atomic.potato
struct S
{
    struct VTable
    {
        int (__thiscall *f)(void *, void *);
    };

    char padding[0x1c];
    void *field1c;
    unsigned char equal(void *a, void *b);
};

unsigned char S::equal(void *a, void *b)
{
    int x = ((VTable *)*(void **)field1c)->f(field1c, a);
    int y = ((VTable *)*(void **)field1c)->f(field1c, b);
    return x == y;
}
