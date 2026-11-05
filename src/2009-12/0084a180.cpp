// from server: 88% by atomic.potato
struct CXTPControlSelector
{
    void *field0;
    void *field4;
    void *field8;
    void f(void *);
};

void CXTPControlSelector::f(void *arg)
{
    void *object = field4;
    if (object == 0 || arg == 0)
        return;

    void **vtable = *(void ***)object;
    void *result = ((void *(__thiscall *)(void *, void *))vtable[12])(object, arg);

    if (field8 == 0 && result != 0)
        field8 = result;
}
