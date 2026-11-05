// from server: 71% by atomic.potato
struct XItem
{
    void **vtable;
    void f();
};

extern "C" void __cdecl call_47d070(void *);

void XItem::f()
{
    void *result = vtable[1];
    result = ((void *(__thiscall *)(void *, int, int))result)(vtable, 0, 0);
    call_47d070(result);
}
