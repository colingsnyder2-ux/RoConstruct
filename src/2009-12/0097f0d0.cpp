// from server: 42% by atomic.potato
struct S
{
    void f();
};

extern "C" void __cdecl func_004e8f30();

void S::f()
{
    ((void (__thiscall *)(void*))func_004e8f30)((void*)0x00b7dc14);
}
