// from server: 44% by atomic.potato
struct S
{
    int value;
};

struct T
{
    int (**vtable)(int, int);
    int pad[5];
    int (__thiscall *call)(int, int);
};

struct U
{
    int *value;
};

int __stdcall f(T *object, U *arg)
{
    int *p = object->pad[0] ? object->pad + 7 : 0;
    int *q = arg->value;
    return object->vtable[0]((int)p, (int)(q + 1));
}
