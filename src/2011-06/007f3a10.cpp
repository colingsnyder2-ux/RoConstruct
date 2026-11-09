// from server: 41% by atomic.potato
struct S
{
    int vtable_function;
    char pad[40];
    float x;
    float y;
    S *f(void *);
};

S *S::f(void *value)
{
    short *p = (short *)value;
    x = (float)p[4];
    y = (float)p[5];
    ((void (__thiscall *)(S *))(*(int **)this + 44))(this);
    return this;
}
