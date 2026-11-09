// from server: 40% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S_func_006782a0 {
    char pad0[132];
    int m_x;
    int f();
};

struct RefCounted {
    void** vtbl;
    long ref1;
    long ref2;
};

struct Inner {
    char pad0[0x220];
    void* ptr220;
    RefCounted* ptr224;
    RefCounted* ptr228;
    RefCounted* ptr22c;
};

struct CRobloxWnd {
    void* vtbl;
    char pad0[0x21c];
    void* ptr220;
    RefCounted* ptr224;
    RefCounted* ptr228;
    RefCounted* ptr22c;
    void RenderRequestJob();
};

void CRobloxWnd::RenderRequestJob()
{
    this->vtbl = (void*)0xb5f4a0;
    if (this->ptr220 != 0) {
        int r = ((S_func_006782a0*)this->ptr228)->f();
        if (r != 0) {
            RefCounted* p224 = this->ptr224;
            if (p224 != 0) {
                _InterlockedExchangeAdd(&p224->ref1, 1);
            }
            void* a = this->ptr220;
            void* b = this->ptr224;
            (void)a;
            (void)b;
            ((void(__thiscall*)(void*, void*, void*))0x6782a0)((void*)r, a, b);
            ((void(__thiscall*)(void*, void*))0x978570)((void*)0, (void*)0);
        }
    }
    RefCounted* p22c = this->ptr22c;
    if (p22c != 0) {
        if (_InterlockedExchangeAdd(&p22c->ref1, -1) == 1) {
            ((void(__thiscall*)(RefCounted*))p22c->vtbl[1])(p22c);
            if (_InterlockedExchangeAdd(&p22c->ref2, -1) == 1) {
                ((void(__thiscall*)(RefCounted*))p22c->vtbl[2])(p22c);
            }
        }
    }
    RefCounted* p224 = this->ptr224;
    if (p224 != 0) {
        if (_InterlockedExchangeAdd(&p224->ref1, -1) == 1) {
            ((void(__thiscall*)(RefCounted*))p224->vtbl[1])(p224);
            if (_InterlockedExchangeAdd(&p224->ref2, -1) == 1) {
                ((void(__thiscall*)(RefCounted*))p224->vtbl[2])(p224);
            }
        }
    }
    ((void(__thiscall*)(CRobloxWnd*))0x978670)(this);
}
