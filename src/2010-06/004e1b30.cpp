// from server: 50% by atomic.potato
struct S
{
    void f(void* p, int n);
};

void __thiscall S::f(void* p, int n)
{
    ((void (__thiscall *)(S*, void*))0x004d91b0)(this, p);
    ((void (__thiscall *)(S*, void*))0x004d91b0)(this, (char*)p + 2);
}
