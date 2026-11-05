// from server: 35% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    long ref1;
    long ref2;
};

struct Inner {
    void* vptr;
    void* field4;
};

struct Obj78 {
    void* vptr;
    Inner* getInner(Inner* out);
};

struct Obj74 {
    char pad[0x130];
    void* vptr;
};

struct CRobloxDoc {
    char pad[0x74];
    Obj74* field74;
    Obj78* field78;
    void func();
};

void sub_40D550(void*);
void sub_5595A0(void*);

void CRobloxDoc::func()
{
    Inner local14;
    Inner local0c;
    RefCounted* local18;
    void* local1c;

    this->field78->getInner(&local14);

    RefCounted* p = (RefCounted*)local14.field4;
    local18 = p;
    if (p != 0) {
        _InterlockedExchangeAdd(&p->ref1, 1);
    }

    sub_40D550(&local1c);

    if (local18 != 0) {
        if (_InterlockedExchangeAdd(&local18->ref1, -1) == 1) {
            void** vt = (void**)local18->vptr;
            ((void (__cdecl*)(RefCounted*))vt[1])(local18);
            if (_InterlockedExchangeAdd(&local18->ref2, -1) == 1) {
                void** vt2 = (void**)local18->vptr;
                ((void (__cdecl*)(RefCounted*))vt2[2])(local18);
            }
        }
    }

    this->field78->getInner(&local0c);

    void* eax = local0c.vptr;
    void* edx;
    if (eax != 0) {
        edx = (char*)eax + 0x160;
    } else {
        edx = 0;
    }

    Obj74* o = this->field74;
    void** vt = (void**)((char*)o + 0x130);
    void* obj = *vt;
    void** vtbl = (void**)obj;
    ((void (__cdecl*)(void*, void*))vtbl[4])(obj, edx);

    if (local0c.vptr != 0) {
        RefCounted* q = (RefCounted*)local0c.vptr;
        if (_InterlockedExchangeAdd(&q->ref1, -1) == 1) {
            void** vt2 = (void**)q->vptr;
            ((void (__cdecl*)(RefCounted*))vt2[1])(q);
            if (_InterlockedExchangeAdd(&q->ref2, -1) == 1) {
                void** vt3 = (void**)q->vptr;
                ((void (__cdecl*)(RefCounted*))vt3[2])(q);
            }
        }
    }

    sub_5595A0(&local1c);
}
