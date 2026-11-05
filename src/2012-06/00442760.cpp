// from server: 40% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    int refCount;
    virtual void Release() = 0;
    virtual void DeleteThis() = 0;
};

struct CMainFrame {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    void* method(int, int, int, int, RefCounted*, int, int, int, int);
};

void* CMainFrame::method(int a1, int a2, int a3, int a4, RefCounted* a5, int a6, int a7, int a8, int a9) {
    field_0 = 0;
    field_4 = a1;
    field_8 = a2;
    field_C = a3;
    field_10 = a4;
    if (a5) {
        _InterlockedExchangeAdd((volatile long*)((char*)a5 + 4), 1);
    }
    field_14 = a6;
    field_18 = a7;
    field_1C = a8;
    int (__thiscall *fn)(CMainFrame*) = *(int (__thiscall **)(CMainFrame*))(*(int*)this + 4);
    fn(this);
    RefCounted* v = (RefCounted*)field_1C;
    field_1C = -1;
    if (v) {
        long old = _InterlockedExchangeAdd((volatile long*)((char*)v + 4), -1);
        if (old == 1) {
            int (__stdcall *release)(RefCounted*) = *(int (__stdcall **)(RefCounted*))(*(int*)v + 4);
            release(v);
            long old2 = _InterlockedExchangeAdd((volatile long*)((char*)v + 8), -1);
            if (old2 == 1) {
                int (__stdcall *deleteThis)(RefCounted*) = *(int (__stdcall **)(RefCounted*))(*(int*)v + 8);
                deleteThis(v);
            }
        }
    }

    return this;
}
