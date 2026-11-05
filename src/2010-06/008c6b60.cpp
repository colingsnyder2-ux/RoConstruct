// from server: 69% by atomic.potato
struct S
{
    int *vtable;
    int value;
    int unused;
    int offset;
    int f(int x);
};

int S::f(int x)
{
    return ((int (__thiscall *)(int *, int))(*(int **)(*(int **)this->value + 0xf0)))((int *)this->value, this->offset + x);
}
