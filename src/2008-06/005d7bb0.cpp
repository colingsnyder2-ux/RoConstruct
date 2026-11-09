// from server: 100% by king_originala
struct Base
{
    char data[4];
};

struct Object : Base
{
    char padding[0x10];
};

struct Argument : Object
{
    char padding2[4];
};

struct GetSetImpl
{
    char padding[0x18];
    int (__thiscall *function)(void *, void *);
    int adjustment;
    int index;

    int Invoke(Argument *a, void *b);
};

int GetSetImpl::Invoke(Argument *a, void *b)
{
    char *obj = a ? (char *)a - 0x14 : 0;
    return function(
        obj + 0x150 +
        (*(int *)(*(char **)(obj + 0x150) + index) + adjustment),
        b);
}
