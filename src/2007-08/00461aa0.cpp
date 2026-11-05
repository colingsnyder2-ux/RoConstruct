// from server: 41% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void AddRef();
    void Release();
};

struct Sub1 {
    void destroy();
};

struct Sub2 {
    void destroy();
};

struct CScriptEditor {
    void destroy();
};

void CScriptEditor::destroy()
{
    RefCounted* p;
    Sub1* s1;
    Sub2* s2;

    *(void**)this = (void*)0x794bd4;
    *(void**)((char*)this + 0xec) = (void*)0x794bc8;
    *(void**)((char*)this + 0xf0) = (void*)0x794bb4;
    *(void**)((char*)this + 0x10c) = (void*)0x794ba0;

    {
        int local[2];
        local[0] = 0;
        local[1] = 0;
        ((void (__thiscall*)(void*, int*))0x4616d0)((char*)this + 0x148, local);
    }

    *(void**)((char*)this + 0x148) = (void*)0x7864c8;
    ((void (__thiscall*)(void*))0x63022c)((char*)this + 0x148);

    p = *(RefCounted**)((char*)this + 0x140);
    if (p != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)p + 4), -1) == 1) {
            (*(void (__thiscall**)(RefCounted*))(*(void***)p + 4))(p);
            if (_InterlockedExchangeAdd((volatile long*)((char*)p + 8), -1) == 1) {
                (*(void (__thiscall**)(RefCounted*))(*(void***)p + 8))(p);
            }
        }
    }

    p = *(RefCounted**)((char*)this + 0x138);
    if (p != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)p + 4), -1) == 1) {
            (*(void (__thiscall**)(RefCounted*))(*(void***)p + 4))(p);
            if (_InterlockedExchangeAdd((volatile long*)((char*)p + 8), -1) == 1) {
                (*(void (__thiscall**)(RefCounted*))(*(void***)p + 8))(p);
            }
        }
    }

    p = *(RefCounted**)((char*)this + 0x12c);
    if (p != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)p + 4), -1) == 1) {
            (*(void (__thiscall**)(RefCounted*))(*(void***)p + 4))(p);
            if (_InterlockedExchangeAdd((volatile long*)((char*)p + 8), -1) == 1) {
                (*(void (__thiscall**)(RefCounted*))(*(void***)p + 8))(p);
            }
        }
    }

    ((void (__thiscall*)(void*))0x460c90)((char*)this + 0x10c);
    ((void (__thiscall*)(void*))0x460c00)((char*)this + 0xf0);

    *(void**)((char*)this + 0xec) = (void*)0x794a20;
    ((void (__thiscall*)(void*))0x45df90)(this);
}
