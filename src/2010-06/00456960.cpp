// from server: 44% by atomic.potato
struct ExitCommand
{
    virtual void f();
    char padding[0x78];
    void *field_7c;
    bool helper();
};

void ExitCommand::f()
{
    void *p = field_7c;
    bool result = false;
    if (p)
        result = ((bool (__thiscall *)(void *))(*(void ***)p)[1])(p);

    f();
}
