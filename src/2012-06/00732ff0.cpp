// from server: 42% by atomic.potato
struct S
{
    void f(void*);
};

void __thiscall S::f(void* p)
{
    char* q = (char*)p;
    if (q[0x2ea])
        ((void (__thiscall *)(S*, void*))0x732f70)(this, p);
    else
        ((void (__thiscall *)(S*, void*))0x732e20)(this, p);
}
