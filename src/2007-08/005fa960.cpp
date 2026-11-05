// from server: 44% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RBXName {
    void* p;
};

struct RefCounted {
    void* vptr;
    long refCount;
    long weakCount;
};

struct View {
    char pad[0x294];
    void* field294;
};

struct FactoryProduct {
    void construct();
};

extern "C" void* __cdecl sub_4CE4C0(void*);
extern "C" void __cdecl sub_728640(void*, void*);
extern "C" void __cdecl sub_728460(void*);
extern "C" void __cdecl sub_571330(void*);

void FactoryProduct::construct()
{
    View* view = (View*)this;
    void* name = sub_4CE4C0(0);
    sub_728640(&view->field294, name);
    sub_728460((char*)this + 0xc);
    sub_571330((char*)this + 0x1c);

    RefCounted* rc = *(RefCounted**)((char*)this + 0x5c);
    if (rc != 0) {
        if (_InterlockedExchangeAdd(&rc->refCount, -1) == 1) {
            void (__stdcall *fn)(RefCounted*) = *(void (__stdcall **)(RefCounted*))((char*)rc->vptr + 4);
            fn(rc);
            if (_InterlockedExchangeAdd(&rc->weakCount, -1) == 1) {
                void (__stdcall *fn2)(RefCounted*) = *(void (__stdcall **)(RefCounted*))((char*)rc->vptr + 8);
                fn2(rc);
            }
        }
    }
}
