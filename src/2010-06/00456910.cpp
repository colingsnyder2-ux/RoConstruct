// from server: 100% by atomic.potato
struct ExitCommand
{
    virtual void f();
    char padding[0x78];
    void *field_7c;
};

void ExitCommand::f()
{
    void *p = field_7c;
    if (p)
    {
        void **vtable = *(void ***)p;
        ((void (__thiscall *)(void *))vtable[0])(p);
    }
}
