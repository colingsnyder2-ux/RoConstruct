// from server: 48% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    ((void (__thiscall *)(int))(*(unsigned int *)((char *)this + 0x20)))(-24);
}
