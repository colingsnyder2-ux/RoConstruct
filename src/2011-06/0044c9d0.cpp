// from server: 84% by atomic.potato
extern "C" void __cdecl UnknownCall(void *);

struct S
{
    void *vptr;
    void *f();
};

void *S::f()
{
    void *p = ((void *(__thiscall *)(void *, int, int))(*(void ***)this)[1])(this, 0, 0);
    UnknownCall(p);
    return (void *)0x44c9ba;
}
