// from server: 45% by atomic.potato
struct S_func_0052d7e0 {
    char pad0[0xdc];
    void* m_pdc;
    int f(char arg);
};

extern "C" {
    long __stdcall InterlockedIncrement(long volatile*);
    long __stdcall InterlockedDecrement(long volatile*);
}

int S_func_0052d7e0::f(char arg)
{
    void* p = 0;
    if (this) {
        p = (char*)this + 4;
        InterlockedIncrement((long volatile*)p);
    }
    void* obj = m_pdc;
    void* vtbl = *(void**)((char*)obj + 0x4c);
    void* fn = *(void**)((char*)vtbl + 0x10);
    void* local = 0;
    ((void (__stdcall*)(void**, char))fn)(&local, arg);
    if (local) {
        if (InterlockedDecrement((long volatile*)((char*)local + 4)) == 0) {
            ((void (__thiscall*)(void*))0x483b20)(local);
            if (local) {
                void** v = *(void***)local;
                ((void (__thiscall*)(void*, int))v[0])(local, 1);
            }
        }
        local = 0;
    }
    void** v2 = *(void***)this;
    void (__thiscall* fn2)(void*) = (void (__thiscall*)(void*))v2[9];
    if (!arg) {
        fn2(this);
        float f = *(float*)0xa126e0;
        if (f > 0.0f) {
            void** v3 = *(void***)this;
            ((void (__thiscall*)(void*, float))v3[8])(this, f);
        }
    } else {
        fn2(this);
        if (1.0f > 0.0f) {
            void** v4 = *(void***)this;
            ((void (__thiscall*)(void*, float))v4[8])(this, 0.0f);
        }
    }
    return 0;
}
