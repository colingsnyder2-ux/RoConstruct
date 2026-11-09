// from server: 91% by atomic.potato
struct CSelectionTreeCtrl
{
    void f(int);
};

void CSelectionTreeCtrl::f(int value)
{
    if (value == 0x00B852B0)
    {
        int *vtable = *(int **)((char *)this + 0x60);
        *((unsigned char *)this + 0x5C) |= 1;
        ((void (__thiscall *)(int *, CSelectionTreeCtrl *))vtable[0x15C / 4])(vtable, this);
    }
}
