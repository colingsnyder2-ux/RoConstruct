// from server: 63% by atomic.potato
struct S
{
    int vftable;
    int reserved1;
    int reserved2;
    int reserved3;
    int *object;

    void v();
};

void (__thiscall *jump_target)(S *);

void S::v()
{
    vftable = 0x99ff40;
    reserved3 = 0x99ff38;
    reserved3 = 0x99fdd8;

    if (object != 0)
    {
        int **p = (int **)object;
        int *vtable = *p;
        void (__thiscall *f)(int *) =
            (void (__thiscall *)(int *))vtable[4];
        f(object);
    }

    jump_target(this);
}
