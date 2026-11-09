// from server: 53% by atomic.potato
extern "C" void __declspec(noreturn) __stdcall rbx_exception_destructor(void*);

struct S
{
    void f();
    void* vtable;
    char padding[12];
    void* object;
};

void S::f()
{
    vtable = (void*)0xA02844;
    *(void**)((char*)this + 12) = (void*)0xA0283C;
    *(void**)((char*)this + 12) = (void*)0xA00968;

    void* p = object;
    if (p)
    {
        void** table = *(void***)p;
        void (__thiscall *destroy)(void*) =
            (void (__thiscall *)(void*))table[4];
        destroy(p);
    }

    rbx_exception_destructor(this);
}
