// from server: 32% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    virtual void slot4();
    virtual void slot8();
    long ref1;
    long ref2;
};

struct Obj {
    void* vptr;
    char pad0[0x14];
    void* field18;
    char pad1[0x4];
    void* field20;
    char pad2[0x18];
    RefCounted* field3c;
    RefCounted* field44;
};

extern void __stdcall G1_func_00a3a1bc(void*);
extern void __stdcall G1_func_0089e1a4(void*);

void Obj_release(RefCounted* p)
{
    if (p) {
        if (_InterlockedExchangeAdd(&p->ref1, -1) == 1) {
            p->slot4();
            if (_InterlockedExchangeAdd(&p->ref2, -1) == 1) {
                p->slot8();
            }
        }
    }
}

void Obj_dtor(Obj* self)
{
    self->vptr = (void*)0x8d754c;
    Obj_release(self->field44);
    Obj_release(self->field3c);
    if (self->field18) {
        void (*fn)(void*, void*, int) = *(void (**)(void*, void*, int))self->field18;
        if (fn) {
            fn(self->field20, self->field20, 2);
        }
        self->field18 = 0;
    }
    G1_func_00a3a1bc((void*)0xa3a1bc);
    self->vptr = (void*)0x8afff4;
    G1_func_0089e1a4((void*)0x89e1a4);
}
