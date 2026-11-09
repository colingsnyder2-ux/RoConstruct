// from server: 100% by atomic.potato
struct S
{
    struct V
    {
        void *vtable;
    };

    char padding[0x20];
    V *p;
    int f(void *);
};

int S::f(void *arg)
{
    V *v = p;
    int result = ((int (__thiscall *)(V *, void *))((void **)v->vtable)[3])(v, arg);
    if (result)
        return result + 0x1c;
    return 0;
}
