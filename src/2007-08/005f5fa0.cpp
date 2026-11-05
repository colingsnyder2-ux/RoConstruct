// from server: 51% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RBXName {
    void* rep;
};

struct RefCounted {
    void* vptr;
    long refCount;
};

struct CreatorBase {
    void* vptr;
};

struct FactoryProduct {
    char pad[0xe8];
    void* field_e8;
    void* field_ec;
    void setField(void*);
};

extern "C" void __cdecl sub_49D670(void*, void*);
extern "C" void __cdecl sub_402A60(void*, void*);
extern "C" void __cdecl sub_444710(void*, void*);
extern "C" void __cdecl sub_495B10(void*, void*, void*);

void FactoryProduct::setField(void* value)
{
    if (this->field_e8 == value)
        return;

    void* local;
    sub_49D670(&local, value);
    this->field_e8 = *(void**)local;
    void* p = (char*)local + 4;
    sub_402A60((char*)this + 0xec, p);

    void* ref = local;
    if (ref) {
        long old = _InterlockedExchangeAdd((volatile long*)((char*)ref + 4), -1);
        if (old == 1) {
            void** vt = *(void***)ref;
            ((void (__thiscall*)(void*))vt[1])(ref);
            old = _InterlockedExchangeAdd((volatile long*)((char*)ref + 8), -1);
            if (old == 1) {
                void** vt2 = *(void***)ref;
                ((void (__thiscall*)(void*))vt2[2])(ref);
            }
        }
    }

    sub_444710(this, (void*)0x8c7df0);

    void* a = this->field_e8;
    void* b = this->field_ec;
    void* args[2];
    args[0] = a;
    args[1] = b;
    if (b) {
        _InterlockedExchangeAdd((volatile long*)((char*)b + 4), 1);
    }
    sub_495B10((void*)0x8c7dcc, (char*)this + 4, args);
}
