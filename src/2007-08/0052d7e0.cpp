// from server: 21% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" double __cdecl clock(void);
extern "C" void __cdecl _invalid_parameter_noinfo(void);

struct RefCounted {
    void AddRef() {
        _InterlockedExchangeAdd((volatile long*)((char*)this + 4), 1);
    }
    void Release() {
        if (_InterlockedExchangeAdd((volatile long*)((char*)this + 4), -1) == 1) {
            (*(void(__thiscall**)(void*))*(void**)this)(this);
        }
    }
};

struct SignalBase {
    char pad[0x24];
};

struct RunService {
    char pad0[0x150];
    SignalBase sig150;
    char pad1[0x20];
    char flag158;
    char pad2[0x34];
    float f18c;
    char pad3[0x8];
    void* list194;
    char pad4[0x8];
    void* list19c;
    void* list1a0;
    void* list1a4;
    void* list1a8;
    void* list1ac;

    void func(double dt, void* a, void* b);
};

void RunService::func(double dt, void* a, void* b) {
    double t0 = clock();
    double accum = 0.0;
    double t1 = clock();
    double elapsed = t1 - t0;

    while (true) {
        void* head = list1a0;
        void* node = list19c;
        void* cur = head;
        while (cur != node) {
            void* item = *(void**)((char*)cur + 0xc);
            void* vtbl = *(void**)item;
            void (__thiscall* fn)(void*, double) = *(void(__thiscall**)(void*, double))((char*)vtbl + 4);
            fn(item, elapsed);
            cur = *(void**)cur;
        }

        if (elapsed <= 0.0) {
            t0 = clock();
        }

        RefCounted* rc = (RefCounted*)a;
        if (rc) rc->AddRef();

        if (flag158 == 0) {
            float f = f18c;
            void* item = (void*)a;
            void* vtbl = *(void**)item;
            void (__thiscall* fn)(void*, float) = *(void(__thiscall**)(void*, float))((char*)vtbl + 4);
            fn(item, f);
            accum += f18c;
            continue;
        }

        if (rc) rc->Release();
        break;
    }
}
