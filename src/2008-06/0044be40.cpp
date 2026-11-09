// from server: 100% by king_originala
void __cdecl operator delete(void*);

extern "C" void __stdcall cleanup(void*);
extern "C" void (__stdcall *DeleteCriticalSection)(void*);

struct Interface {
    virtual void __stdcall slot0() = 0;
    virtual void __stdcall slot1() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

struct S {
    unsigned int unused0;
    unsigned int active;
    unsigned int unused8;
    unsigned int initialized;
    unsigned char criticalSection[24];
    Interface* object;

    S* destroy(unsigned int flags);
};

S* S::destroy(unsigned int flags) {
    if (active) {
        if (initialized) {
            cleanup(&active);
            initialized = 0;
        }
        if (object)
            object->Release();
        DeleteCriticalSection(criticalSection);
        active = 0;
    }
    if (flags & 1)
        operator delete(this);
    return this;
}
