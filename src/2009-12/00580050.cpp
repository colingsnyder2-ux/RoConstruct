// from server: 32% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall EnterCriticalSection(void*);
extern "C" void __stdcall LeaveCriticalSection(void*);
extern "C" void __cdecl _invalid_parameter_noinfo();

struct RefCounted {
    void* vptr;
    long refcount;
    long weakref;
};

struct Node {
    Node* next;
    char pad[8];
    void* data;
};

struct Container {
    char pad0[4];
    void* cs;
    char pad1[0x1d4];
    void* listHead;
};

struct RbxSceneUpdater {
    void* vptr;
    void* cs;
    char pad0[0x1d4];
    void* listHead;
    void update();
};

extern "C" void __stdcall sub_57f240(void*, void*, void*);
extern "C" void __stdcall sub_57ee30(void*, void*);
extern "C" void __stdcall sub_6a2ce0(void*, void*);
extern "C" char __cdecl sub_4f2730(void*);
extern "C" void __cdecl sub_7f385a(void*);
extern "C" void __stdcall sub_57c8a0(void*);

extern void* g_98b204;
extern void* g_98b200;
extern void* g_98b760;

void RbxSceneUpdater::update()
{
    char buf[0x60];
    void* local18;
    void* local1c;
    void* local28;
    void* local3c;
    void* local44;
    void* local50;
    void* local54;
    void* local58;

    sub_57f240(&buf[0x10], &buf[0x14], &buf[0x20]);

    local1c = &this->cs;
    local50 = 0;

    EnterCriticalSection(g_98b204);
    sub_57ee30(&local18, &this->listHead);
    LeaveCriticalSection(g_98b200);

    void* edi = *(void**)local3c;
    void* ebp = local28;
    void* esi = local3c;

    while (edi != esi) {
        if (ebp != 0 && ebp != local28) {
            _invalid_parameter_noinfo();
        }
        if (ebp == 0) {
            _invalid_parameter_noinfo();
            void* eax = 0;
            if (edi == *(void**)((char*)eax + 0x14)) {
                _invalid_parameter_noinfo();
            }
            sub_6a2ce0((char*)edi + 0xc, &local18);
            void* p = local18;
            if (p != 0) {
                if (sub_4f2730(p)) {
                    void* vt = *(void**)this;
                    void* fn = *(void**)((char*)vt + 0x20);
                    void* arg = &local18;
                    ((void (__thiscall*)(void*, void*))fn)(this, arg);
                }
            }
            void* r = local1c;
            if (r != 0) {
                if (_InterlockedExchangeAdd((volatile long*)((char*)r + 4), -1) == 1) {
                    void* vt = *(void**)r;
                    void* fn = *(void**)((char*)vt + 4);
                    ((void (__thiscall*)(void*))fn)(r);
                    if (_InterlockedExchangeAdd((volatile long*)((char*)r + 8), -1) == 1) {
                        void* vt2 = *(void**)r;
                        void* fn2 = *(void**)((char*)vt2 + 8);
                        ((void (__thiscall*)(void*))fn2)(r);
                    }
                }
            }
            if (ebp == 0) {
                _invalid_parameter_noinfo();
                void* eax = 0;
                if (edi == *(void**)((char*)eax + 0x14)) {
                    _invalid_parameter_noinfo();
                }
                edi = *(void**)edi;
                continue;
            }
            ebp = *(void**)ebp;
        } else {
            ebp = *(void**)ebp;
        }
    }

    if (local50 != 0) {
        sub_7f385a(local50);
    }
    local50 = 0;
    local54 = 0;
    local58 = 0;

    sub_7f385a(local44);

    local18 = &local28;
    sub_57c8a0(&local28);

    sub_7f385a(local3c);
    sub_7f385a(local28);
}
