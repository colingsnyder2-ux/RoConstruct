// from server: 61% by atomic.potato
extern "C" void __stdcall std_bad_cast_destructor(void*);

struct S
{
    void f();
    void* v18;
};

void S::f()
{
    *(void**)this = (void*)0x00baa954;
    *(void**)((char*)this + 0x14) = (void*)0x00baa94c;
    *(void**)((char*)this + 0x14) = (void*)0x00b43e60;

    if (v18 != 0)
    {
        void** table = *(void***)v18;
        ((void (__thiscall *)(void*))table[4])(v18);
    }

    *(void**)this = (void*)0x00baa87c;
    std_bad_cast_destructor(this);
}
