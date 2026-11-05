// from server: 27% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    char pad0[4];
    volatile long ref;
    char pad8[4];
    virtual void v1();
    virtual void v2();
};

struct Obj {
    char pad0[0x20];
    int field20;
    Inner* field24;
    int field28;
    Inner* field2c;
};

struct Sub {
    char pad0[0x190];
    Obj obj;

    void method(int a, int b, int c, int d);
};

extern "C" void __fastcall sub_40d550(void*);
extern "C" void __fastcall sub_410d40(void*);
extern "C" void __fastcall sub_432530(void*, void*);
extern "C" void __fastcall sub_423240(void*, void*);
extern "C" void __fastcall sub_402a60(void*, void*);
extern "C" void __fastcall sub_5595a0(void*);
extern "C" void __fastcall sub_461e20(void*);
extern "C" void* __cdecl sub_49d670(void*, void*);

void Sub::method(int a, int b, int c, int d) {
    Obj* o = &obj;
    o->field24 = (Inner*)a;
    if (o->field24) {
        _InterlockedExchangeAdd(&o->field24->ref, 1);
    }
    sub_40d550(&a);
    if (o->field28) {
        sub_432530((char*)o->field28 + 0xe8, (void*)((char*)this - 0x190 + 4));
    }
    o->field28 = 0;
    Inner* p = o->field2c;
    o->field2c = 0;
    if (p) {
        if (_InterlockedExchangeAdd(&p->ref, -1) == 1) {
            p->v1();
            if (_InterlockedExchangeAdd((volatile long*)((char*)p + 8), -1) == 1) {
                p->v2();
            }
        }
    }
    o->field20 = 0;
    Inner* q = o->field24;
    o->field24 = 0;
    if (q) {
        if (_InterlockedExchangeAdd(&q->ref, -1) == 1) {
            q->v1();
            if (_InterlockedExchangeAdd((volatile long*)((char*)q + 8), -1) == 1) {
                q->v2();
            }
        }
    }
    sub_5595a0(&b);
    if (a) {
        o->field20 = a;
        sub_402a60(&o->field24, &c);
        int v = o->field20;
        void* tmp = &v;
        sub_40d550(&tmp);
        int r = o->field20;
        if (r) {
            sub_410d40((void*)r);
        } else {
            r = 0;
        }
        void* res = sub_49d670(&b, (void*)r);
        o->field28 = *(int*)res;
        sub_402a60(&o->field2c, (char*)res + 4);
        Inner* s = (Inner*)b;
        if (s) {
            if (_InterlockedExchangeAdd(&s->ref, -1) == 1) {
                s->v1();
                if (_InterlockedExchangeAdd((volatile long*)((char*)s + 8), -1) == 1) {
                    s->v2();
                }
            }
        }
        if (o->field28) {
            sub_423240((char*)o->field28 + 0xe8, (void*)((char*)this - 0x190 + 4));
        }
        sub_5595a0(&c);
    }
    if (!o->field28) {
        sub_461e20((char*)this - 0x190);
    }
    Inner* t = (Inner*)c;
    if (t) {
        if (_InterlockedExchangeAdd(&t->ref, -1) == 1) {
            t->v1();
            if (_InterlockedExchangeAdd((volatile long*)((char*)t + 8), -1) == 1) {
                t->v2();
            }
        }
    }
    Inner* u = (Inner*)d;
    if (u) {
        if (_InterlockedExchangeAdd(&u->ref, -1) == 1) {
            u->v1();
            if (_InterlockedExchangeAdd((volatile long*)((char*)u + 8), -1) == 1) {
                u->v2();
            }
        }
    }
}
