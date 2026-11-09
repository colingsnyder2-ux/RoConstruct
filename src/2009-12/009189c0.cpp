// from server: 18% by atomic.potato
struct Sky
{
    int pad0c[4];
    void f();
};

void __thiscall Sky::f()
{
    if (pad0c[3] != 0)
        ((void (__thiscall *)(int, Sky *))0x918a60)(pad0c[3], this);
}
