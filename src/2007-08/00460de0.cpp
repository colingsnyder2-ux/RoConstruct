// from server: 37% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void AddRef();
    void Release();
};

struct Listener {
    void* vptr;
    RefCounted* ptr8;
    void* ptrC;
    void Destroy();
};

struct Base {
    void* vptr;
};

void __stdcall sub_437B80(Listener* self);

void Listener::Destroy()
{
    this->vptr = (void*)0x794b88;
    if (this->ptrC != 0) {
        sub_437B80(this);
    }
    RefCounted* p = this->ptr8;
    if (p != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)p + 4), -1) == 1) {
            void** vt = *(void***)p;
            ((void (__thiscall*)(RefCounted*))vt[1])(p);
            if (_InterlockedExchangeAdd((volatile long*)((char*)p + 8), -1) == 1) {
                void** vt2 = *(void***)p;
                ((void (__thiscall*)(RefCounted*))vt2[2])(p);
            }
        }
    }
    this->vptr = (void*)0x787f68;
}
