// from server: 41% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void AddRef();
    void Release();
};

struct Sub1 {
    void Set(void*);
};

struct Sub2 {
    void Set(void*);
};

struct CSelectionPropGrid {
    char pad[0x17c];
    Sub1 sub1;
    char pad2[0x1c4 - 0x17c - sizeof(Sub1)];
    Sub2 sub2;
    void Func(void*, void*, void*);
};

void CSelectionPropGrid::Func(void* a, void* b, void* c)
{
    void* p = 0;
    if (this)
        p = (char*)this + 0x17c;
    if (b)
        ((Sub1*)((char*)b + 0x8c))->Set(p);
    ((Sub2*)((char*)this + 0x1c4))->Set(b);
    if (c) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)c + 4), -1) == 1) {
            (*(void (***)(void*))c)[1](c);
            if (_InterlockedExchangeAdd((volatile long*)((char*)c + 8), -1) == 1)
                (*(void (***)(void*))c)[2](c);
        }
    }
}
