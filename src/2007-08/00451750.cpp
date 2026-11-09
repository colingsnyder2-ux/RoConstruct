// from server: 28% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    long refcount;
    long weakrefcount;
};

struct Obj0 {
    void* vptr;
    void (__thiscall *fn)(void*, bool);
};

struct Obj1 {
    void* vptr;
    void (__thiscall *fn)(void*, bool);
};

struct Inner {
    char pad[0x14c];
    int field;
};

struct Outer {
    char pad[0x78];
    void* ptr78;
};

extern "C" void* __stdcall sub_403800(void* out, void* arg);
extern "C" void* __stdcall sub_403830(void* out, void* arg);
extern "C" void __stdcall sub_40d550(void* p);
extern "C" void* __stdcall sub_450ec0(void* p);
extern "C" void __stdcall sub_5595a0(void* p);

struct ReportAbuseVerb {
    void method(int arg);
};

void ReportAbuseVerb::method(int arg)
{
    void* local14;
    void* local10;
    void* local0c;
    void* local24;
    void* local38;
    void* local28;

    void* p = sub_403800(&local14, ((Outer*)this)->ptr78);
    void* a = *(void**)p;
    void* b = *(void**)((char*)p + 4);
    local38 = 0;
    local24 = &local14;
    local10 = a;
    local0c = b;
    if (b) {
        _InterlockedExchangeAdd((volatile long*)((char*)b + 4), 1);
    }
    sub_40d550(&local24);

    void* edi = local10;
    if (edi) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)edi + 4), -1) == 1) {
            void* vt = *(void**)edi;
            ((void (__thiscall*)(void*))*(void**)((char*)vt + 4))(edi);
            if (_InterlockedExchangeAdd((volatile long*)((char*)edi + 8), -1) == 1) {
                void* vt2 = *(void**)edi;
                ((void (__thiscall*)(void*))*(void**)((char*)vt2 + 8))(edi);
            }
        }
    }

    void* r = sub_403830(&local0c, this);
    void* ecx = *(void**)r;
    void* inner = sub_450ec0(ecx);
    int field = *(int*)((char*)inner + 0x14c);

    void* eax = local0c;
    if (eax) {
        void* esi = eax;
        if (_InterlockedExchangeAdd((volatile long*)((char*)esi + 4), -1) == 1) {
            void* vt = *(void**)esi;
            ((void (__thiscall*)(void*))*(void**)((char*)vt + 4))(esi);
            if (_InterlockedExchangeAdd((volatile long*)((char*)esi + 8), -1) == 1) {
                void* vt2 = *(void**)esi;
                ((void (__thiscall*)(void*))*(void**)((char*)vt2 + 8))(esi);
            }
        }
    }

    void* obj = local38;
    void* vt = *(void**)obj;
    void* fn = *(void**)vt;
    bool flag = (field != 0);
    ((void (__thiscall*)(void*, bool))fn)(obj, flag);

    sub_5595a0(&local24);
}
