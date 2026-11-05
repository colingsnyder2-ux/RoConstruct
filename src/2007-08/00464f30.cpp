// from server: 53% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall DeleteCriticalSection(void*);

struct RefCounted {
    void AddRef();
    void Release();
};

struct Obj {
    void* vptr;
    void (__stdcall *fn20)(void*);
    void (__stdcall *fn8)(void*);
};

struct Sub {
    char pad[0xe8];
};

struct Sub2 {
    char pad[0x118];
};

struct DxUserInput {
    char pad0[0x28];
    void* m_28;
    void* m_2c;
    char pad1[0x50 - 0x30];
    void* m_50;
    char pad2[0x188 - 0x54];
    Obj* m_188;
    Obj* m_18c;
    Obj* m_190;
    void* m_194;
    RefCounted* m_198;
    void dtor();
};

extern "C" void __cdecl func_62ff26(void*);
extern "C" void __cdecl func_77d304(void*);
extern "C" void* __cdecl func_450d00(void*);
extern "C" void __cdecl func_432530(void*, void*);
extern "C" void __cdecl func_463830(void*);

void DxUserInput::dtor()
{
    m_28 = (void*)0x795bd0;
    m_2c = (void*)0x795bc4;
    *(void**)this = (void*)0x795bdc;

    if (m_194) {
        void* p = func_450d00(m_194);
        if (p) {
            func_432530((char*)p + 0xe8, &m_2c);
        }
    }
    if (m_194) {
        void* p = func_450d00(m_194);
        if (p) {
            func_432530((char*)p + 0x118, &m_28);
        }
    }

    if (m_18c) {
        Obj* o = m_18c;
        o->fn20(o);
        o = m_18c;
        if (o) {
            o->fn8(o);
            m_18c = 0;
        }
    }
    if (m_190) {
        Obj* o = m_190;
        o->fn20(o);
        o = m_190;
        if (o) {
            o->fn8(o);
            m_190 = 0;
        }
    }
    if (m_188) {
        Obj* o = m_188;
        o->fn8(o);
        m_188 = 0;
    }

    func_62ff26(m_50);

    RefCounted* r = m_198;
    if (r) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)r + 4), -1) == 1) {
            void** vt = *(void***)r;
            ((void(__stdcall*)(void*))vt[1])(r);
            if (_InterlockedExchangeAdd((volatile long*)((char*)r + 8), -1) == 1) {
                void** vt2 = *(void***)r;
                ((void(__stdcall*)(void*))vt2[2])(r);
            }
        }
    }

    if (m_190) {
        Obj* o = m_190;
        o->fn8(o);
    }
    if (m_18c) {
        Obj* o = m_18c;
        o->fn8(o);
    }
    if (m_188) {
        Obj* o = m_188;
        o->fn8(o);
    }

    DeleteCriticalSection((char*)this + 0x34);

    m_2c = (void*)0x795b60;
    m_28 = (void*)0x795b54;
    func_463830(this);
}
