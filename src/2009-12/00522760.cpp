// from server: 26% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl operator_delete(void*);

struct RefCounted {
    void* vfptr;
    long refcount;
};

struct String {
    char pad[0x1c];
};

struct Inner {
    void* ptr;
    char pad[0x0c];
    void* a;
    void* b;
    void* c;
    void* d;
    void* e;
};

struct Players {
    Inner* field0;
    char pad0[4];
    String* field8;
    void init(Inner*);
    void destroy();
};

extern "C" void __stdcall sub_98b6f0(void*);
extern "C" void __stdcall sub_98b6e4(void*);
extern "C" void __stdcall sub_7e4ba0(void*, void*);
extern "C" void __stdcall sub_7e47e0(void*);
extern "C" void __stdcall sub_7f385a(void*);
extern "C" void* __stdcall sub_7f3860(unsigned int);
extern "C" void __stdcall sub_854a90(void*, void*, void*);
extern "C" void __stdcall sub_5176b0(void*, void*);
extern "C" void __stdcall sub_521dd0(void*, void*);
extern "C" void __stdcall sub_51bee0(void*);

void Players::init(Inner* p) {
    field0 = p;
    sub_521dd0(&field0, p);
    sub_854a90(&field0, p, p);
    field8 = 0;
}

void Players::destroy() {
    if (field8) {
        sub_7e47e0(field8);
        sub_7f385a(field8);
    }
}

void Players_ctor(Players* self, void* a, void* b, void* c, void* d, void* e, void* f, void* g) {
    Inner* inner = 0;
    void* local[8];
    self->field0 = 0;
    self->field8 = 0;

    inner = (Inner*)sub_7f3860(0x28);
    if (inner) {
        void* rc = sub_7f3860(4);
        if (rc) {
            *(void**)rc = inner;
        } else {
            rc = 0;
        }
        inner->ptr = rc;
        inner->a = 0;
        inner->b = 0;
        inner->c = 0;
        inner->d = 0;
        inner->e = 0;
    } else {
        inner = 0;
    }

    self->field0 = inner;
    sub_521dd0(&self->field0, inner);
    sub_854a90(&self->field0, inner, inner);
    self->field8 = 0;

    String* s = (String*)sub_7f3860(0x14);
    if (s) {
        sub_98b6f0(local);
        void* ref = self->field0;
        void* rc = 0;
        if (ref) {
            rc = *(void**)ref;
            if (rc) {
                _InterlockedExchangeAdd((volatile long*)((char*)rc + 4), 1);
            }
        }
        sub_5176b0(local, ref);
        sub_51bee0(local);
        sub_7e4ba0(s, local);
    } else {
        s = 0;
    }

    String* old = self->field8;
    self->field8 = s;
    if (old) {
        sub_7e47e0(old);
        sub_7f385a(old);
    }

    sub_98b6e4(local);
}
