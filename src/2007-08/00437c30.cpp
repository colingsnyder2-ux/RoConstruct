// from server: 40% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    long refCount;
};

struct Inner {
    void* vptr;
    long refCount;
};

struct StringLike {
    void* vptr;
};

struct S {
    void* vptr;
    Inner* inner;
    void* field8;
    void* fieldC;
    StringLike str14;
    void destroy();
    ~S();
};

extern "C" void __stdcall sub_437B80(S* self);
extern "C" void __stdcall string_dtor(StringLike* self);

void S::destroy()
{
    if (fieldC) {
        sub_437B80(this);
    }
    string_dtor(&str14);
    if (field8) {
        Inner* p = (Inner*)field8;
        if (_InterlockedExchangeAdd(&p->refCount, -1) == 1) {
            void** vt = (void**)p->vptr;
            ((void (__thiscall*)(Inner*))vt[1])(p);
            if (_InterlockedExchangeAdd(&p->refCount, -1) == 1) {
                void** vt2 = (void**)p->vptr;
                ((void (__thiscall*)(Inner*))vt2[2])(p);
            }
        }
    }
}

S::~S()
{
    vptr = (void*)0x78ce10;
    destroy();
    vptr = (void*)0x787f68;
}
