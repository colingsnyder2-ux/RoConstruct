// from server: 100% by atomic.potato
extern "C" void __cdecl continuation();

struct S
{
    void f();
};

void S::f()
{
    *(int*)0x00cb1778 = 0;
    *(int*)((char*)this + 0) = 0x00a5c04c;
    *(int*)((char*)this + 4) = 0x00a5c040;
    *(int*)((char*)this + 0x18) = 0x00a5c034;
    *(int*)((char*)this + 0x1c) = 0x00a5c028;
    continuation();
}
