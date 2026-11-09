// from server: 38% by atomic.potato
struct ExitCommand
{
    virtual void f();
    char padding[0x78];
    void *field_7c;
};

void ExitCommand::f()
{
    void *p = field_7c;
    int result = 0;

    if (p)
    {
        void **vtable = *(void ***)p;
        result = ((int (__thiscall *)(void *))vtable[1])(p) ? 1 : 0;
    }

    ((void (__thiscall *)(void *, int))(*(void ***)this)[0])(this, result);
}
