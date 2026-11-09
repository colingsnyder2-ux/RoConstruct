// from server: 100% by atomic.potato
extern "C" void __cdecl sub_5980D0();

struct S
{
    void f();
};

void S::f()
{
    *(void**)this = (void*)0xA8FAD4;
    *(void**)((char*)this + 4) = (void*)0xA8FACC;
    *(void**)((char*)this + 0x18) = (void*)0xA8FAC0;
    *(void**)((char*)this + 0x1C) = (void*)0xA8FAB4;
    sub_5980D0();
}
