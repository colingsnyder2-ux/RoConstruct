// from server: 34% by atomic.potato
struct Sub {
    char pad[0x90];
    void destroy();
};

struct S {
    char pad0[0x90];
    Sub sub90;
    char pad1[0x1c];
    Sub subb0;
    void destroy();
};

void S::destroy()
{
    subb0.destroy();
    sub90.destroy();
    ((void (__thiscall *)(S *))0x5d2b60)(this);
}
