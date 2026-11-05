// from server: 86% by atomic.potato
struct UnifiedWidget_006757d0
{
    int (**vtable)();
    void f(int value);
};

void UnifiedWidget_006757d0::f(int value)
{
    if (!((char (__thiscall *)(UnifiedWidget_006757d0 *))vtable[24])(this))
        return;

    ((void (__thiscall *)(UnifiedWidget_006757d0 *, int))vtable[31])(this, value);
    ((void (__thiscall *)(UnifiedWidget_006757d0 *, int))0x675750)(this, value);
}
