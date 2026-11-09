// from server: 46% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __stdcall sub_802458(const char*);
extern "C" void* __cdecl sub_4306C0(void*);
extern "C" void __cdecl sub_5773C0(void*);
extern "C" void* __cdecl sub_583380(void*);

struct RefCounted {
    void* vptr;
    long ref1;
    long ref2;
    void Release();
};

void RefCounted::Release() {
    if (_InterlockedExchangeAdd(&ref1, -1) == 1) {
        (*(void(__thiscall**)(RefCounted*))(*(void***)this)[1])(this);
        if (_InterlockedExchangeAdd(&ref2, -1) == 1)
            (*(void(__thiscall**)(RefCounted*))(*(void***)this)[2])(this);
    }
}

struct CDataModelPropGrid {
    void f(int, int);
};

void CDataModelPropGrid::f(int a, int b) {
    void* s = sub_802458("FillTool");
    void* p1 = sub_4306C0(s);
    void* obj = sub_583380((char*)p1 + 0x1c8);
    RefCounted* r1 = *(RefCounted**)((char*)p1 + 0x18);
    if (r1) {
        if (_InterlockedExchangeAdd(&r1->ref1, -1) == 1) {
            (*(void(__thiscall**)(RefCounted*))(*(void***)r1)[1])(r1);
            if (_InterlockedExchangeAdd(&r1->ref2, -1) == 1)
                (*(void(__thiscall**)(RefCounted*))(*(void***)r1)[2])(r1);
        }
    }
    void* p2 = sub_4306C0(s);
    void* arg = 0;
    if (p2)
        arg = (char*)p2 + 0x1f0;
    (*(void(__thiscall**)(void*, void*))(*(void***)obj)[4])(obj, arg);
    RefCounted* r2 = *(RefCounted**)((char*)p2 + 0x1c);
    if (r2) {
        if (_InterlockedExchangeAdd(&r2->ref1, -1) == 1) {
            (*(void(__thiscall**)(RefCounted*))(*(void***)r2)[1])(r2);
            if (_InterlockedExchangeAdd(&r2->ref2, -1) == 1)
                (*(void(__thiscall**)(RefCounted*))(*(void***)r2)[2])(r2);
        }
    }
    sub_5773C0((char*)&a - 0x14);
    *(int*)((char*)&a - 0x14) = 1;
}
