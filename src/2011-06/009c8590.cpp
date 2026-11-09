// from server: 35% by atomic.potato
typedef void (__thiscall *Destructor)(void *);
typedef void (__cdecl *Cleanup)(void *);

extern "C" void __cdecl sub_0080b0ac();
extern "C" Destructor pDestructor;

struct S
{
    void f();
};

void S::f()
{
    sub_0080b0ac();
    pDestructor((char *)this + 0x50);
}
