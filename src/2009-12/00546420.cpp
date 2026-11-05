// from server: 50% by atomic.potato
struct S
{
    void f();
};

typedef void* (__thiscall *Fn1)(void*);
typedef void (__thiscall *Fn2)(void*, void*);

S* __cdecl g1(void*);
void __cdecl g2(void*, void*);

void S::f()
{
    void* value = g1((char*)this + 0xc0);
    g2(this, &value);
}
