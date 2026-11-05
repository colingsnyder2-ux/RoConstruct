// from server: 64% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void AddRef();
    void Release();
};

struct Sub {
    virtual void v0();
    virtual void v1(int);
};

struct Inner {
    char pad0[0xaec];
    void* field_aec;
};

struct Outer {
    char pad0[0x15c];
    Inner* p15c;
    RefCounted* p160;
    char pad1[0x64];
    Sub* p1c8;
    Sub* p1cc;
    Sub* p1d0;
    Sub* p1d4;
    Sub* p1d8;
    Sub* p1dc;
    Sub* p1e0;
    char pad2[4];
    char obj1e4[4];
    char obj1e8[4];
    char obj1ec[4];
};

struct Holder {
    void* p0;
    void* p4;
};

extern "C" void __cdecl sub_5f6b90(Holder*);
extern "C" void __cdecl sub_7f8c90(void*);
extern "C" void __cdecl sub_5f02d0(void*);
extern "C" void __cdecl sub_598330(void*);

struct HelpCommand {
    void func(int);
};

void HelpCommand::func(int arg) {
    Outer* self = (Outer*)this;
    Holder h;
    h.p0 = self->p15c;
    h.p4 = self->p160;
    if (h.p4 != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)h.p4 + 4), 1);
    }
    sub_5f6b90(&h);
    h.p0 = 0;
    if (*(char*)&arg != 0) {
        Inner* p = self->p15c;
        if (p != 0) {
            if (p->field_aec != 0) {
                sub_598330(p->field_aec);
            }
        }
    }
    Sub* s;
    s = self->p1c8;
    self->p1c8 = 0;
    if (s != 0) {
        s->v1(1);
    }
    s = self->p1cc;
    self->p1cc = 0;
    if (s != 0) {
        s->v1(1);
    }
    s = self->p1d0;
    self->p1d0 = 0;
    if (s != 0) {
        s->v1(1);
    }
    s = self->p1d4;
    self->p1d4 = 0;
    if (s != 0) {
        s->v1(1);
    }
    s = self->p1d8;
    self->p1d8 = 0;
    if (s != 0) {
        s->v1(1);
    }
    s = self->p1dc;
    self->p1dc = 0;
    if (s != 0) {
        s->v1(1);
    }
    s = self->p1e0;
    self->p1e0 = 0;
    if (s != 0) {
        s->v1(1);
    }
    sub_7f8c90(self->obj1e4);
    sub_7f8c90(self->obj1e8);
    sub_7f8c90(self->obj1ec);
    sub_5f02d0(&h);
}
