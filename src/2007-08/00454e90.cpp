// from server: 45% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vfptr;
    long refcount;
    long weakrefcount;
};

struct Sub1 {
    void* vfptr;
    char pad[0x50];
};

struct Sub2 {
    void* vfptr;
    char pad[0x50];
};

struct Inner {
    char pad0[0x14];
    void* field14;
    char pad18[0x14];
    void* field2c;
};

struct CStatsItemRecord {
    void* vfptr;
    char pad04[0x50];
    Sub1 sub54;
    char pad58[0x18];
    Sub2 sub70;
    char pad74[0x18];
    RefCounted* ref8c;
    RefCounted* ref90;
    char pad94[0x4];
    Inner* inner98;
    RefCounted* ref9c;
};

extern "C" void __cdecl sub_40d550(void*);
extern "C" void __cdecl sub_432530(void*);
extern "C" void __cdecl sub_4541f0(void*);
extern "C" void __cdecl sub_454280(void*);
extern "C" void __cdecl sub_5595a0(void*);
extern "C" void __cdecl sub_661eb0(void*);

void CStatsItemRecord_dtor(CStatsItemRecord* self)
{
    self->vfptr = (void*)0x7923ec;
    self->sub54.vfptr = (void*)0x792454;
    self->sub70.vfptr = (void*)0x7923d8;

    RefCounted* r8c = self->ref8c;
    RefCounted* r90 = self->ref90;
    if (r90)
        _InterlockedExchangeAdd(&r90->refcount, 1);

    sub_40d550(&self->ref8c);

    Inner* inner = self->inner98;
    if (inner)
        sub_432530(&inner->field14);
    inner = self->inner98;
    if (inner)
        sub_432530(&inner->field2c);

    sub_5595a0(&self->ref8c);

    RefCounted* r9c = self->ref9c;
    if (r9c)
    {
        if (_InterlockedExchangeAdd(&r9c->refcount, -1) == 1)
        {
            void** vt = (void**)r9c->vfptr;
            ((void(__thiscall*)(RefCounted*))vt[1])(r9c);
            if (_InterlockedExchangeAdd(&r9c->weakrefcount, -1) == 1)
            {
                void** vt2 = (void**)r9c->vfptr;
                ((void(__thiscall*)(RefCounted*))vt2[2])(r9c);
            }
        }
    }

    sub_454280(&self->sub70);
    sub_4541f0(&self->sub54);

    RefCounted* r90b = self->ref90;
    if (r90b)
    {
        if (_InterlockedExchangeAdd(&r90b->refcount, -1) == 1)
        {
            void** vt = (void**)r90b->vfptr;
            ((void(__thiscall*)(RefCounted*))vt[1])(r90b);
            if (_InterlockedExchangeAdd(&r90b->weakrefcount, -1) == 1)
            {
                void** vt2 = (void**)r90b->vfptr;
                ((void(__thiscall*)(RefCounted*))vt2[2])(r90b);
            }
        }
    }

    sub_661eb0(self);
}
