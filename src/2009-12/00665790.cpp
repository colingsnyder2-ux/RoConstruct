// from server: 82% by atomic.potato
struct S
{
    void f(int value);
};

extern "C" void __cdecl g(int value);

void S::f(int value)
{
    g(value);
    ((void (__thiscall *)(S*, int))(*(void**)((char*)this + 0x100)))(
        (S*)((char*)this + 0x100), 1);
}
