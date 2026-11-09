// from server: 25% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    volatile long ref1;
    volatile long ref2;
};

struct Str {
    char pad[0x1c];
};

struct EventDescriptor {
    void* vptr;
};

struct Slot {
    void* vptr;
    volatile long ref1;
    volatile long ref2;
};

extern "C" void __stdcall sub_4f5630(void*, void*);
extern "C" void __stdcall sub_598d90(void*, void*);
extern "C" void* __stdcall sub_9ea410(void*, void*);
extern "C" void __stdcall sub_9ea400(void*);

struct Signal {
    void func(void* a, void* b);
};

void Signal::func(void* a, void* b)
{
    void* local1c;
    void* local20;
    void* local24;
    void* local28;
    void* local2c;
    void* local30;
    void* local34;
    void* local38;
    void* local3c;
    void* local40;
    void* local44;
    void* local48;
    void* local4c;

    sub_4f5630(&local1c, a);
    void* edi = *(void**)&local1c;
    void* esi = *(void**)((char*)&local1c + 4);

    local20 = edi;
    local24 = esi;

    if (esi) {
        _InterlockedExchangeAdd((volatile long*)((char*)esi + 4), 1);
    }

    void* ebp = *(void**)&local1c;
    local44 = 0;

    if (ebp) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)ebp + 4), -1) == 1) {
            void** vt = *(void***)ebp;
            ((void (__thiscall*)(void*))vt[1])(ebp);
            if (_InterlockedExchangeAdd((volatile long*)((char*)ebp + 8), -1) == 1) {
                void** vt2 = *(void***)ebp;
                ((void (__thiscall*)(void*))vt2[2])(ebp);
            }
        }
    }

    sub_9ea410(&local20, b);

    void** vt3 = *(void***)edi;
    void (__thiscall* fn)(void*, void*) = (void (__thiscall*)(void*, void*))vt3[2];
    fn(edi, &local20);

    local44 = 0;
    sub_9ea400(&local20);

    sub_598d90(edi, a);

    local44 = (void*)-1;

    if (esi) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)esi + 4), -1) == 1) {
            void** vt4 = *(void***)esi;
            ((void (__thiscall*)(void*))vt4[1])(esi);
            if (_InterlockedExchangeAdd((volatile long*)((char*)esi + 8), -1) == 1) {
                void** vt5 = *(void***)esi;
                ((void (__thiscall*)(void*))vt5[2])(esi);
            }
        }
    }
}
