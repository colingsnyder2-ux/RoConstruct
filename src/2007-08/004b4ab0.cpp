// from server: 28% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RBXString {
    char buf[16];
    unsigned int size;
    unsigned int cap;
};

struct RefCounted {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    long refcount;
};

struct Replicator {
    char pad0[0xec];
    char field_ec[0x1c70];
    char field_1d5c[0x5c];
    char field_1db8[0x60];
    char field_1e18[0x100];

    void ChangePropertyItem(void* arg);
};

extern "C" {
    void __stdcall sub_4a0e60(void*, void*, void*, void*);
    void __stdcall sub_4a4d50(void*, void*, void*);
    void* __cdecl sub_498f60();
    void __cdecl sub_56c3b0(void*);
    void* __stdcall sub_4a3510(void*, int);
    void __cdecl sub_56c0a0(void*, int, void*, void*);
    void __stdcall sub_5bfab0(void*, void*, void*);
    void __cdecl sub_5017c0(void*, void*, void*, void*, void*, void*);
    void __cdecl sub_412dc0(void*, void*);
    void __cdecl sub_630b9e(void*, void*);
    void __stdcall sub_4b4180(void*, void*, int, void*);
    void __stdcall sub_4a63f0(void*, void*);
    void __cdecl sub_630a1e();
    void* __cdecl sub_77e698();
    void* __cdecl sub_77e6d8();
}

void Replicator::ChangePropertyItem(void* arg)
{
    RBXString s1;
    RBXString s2;
    RefCounted* rc;
    int* p;
    int* q;
    int old;
    int v;
    void* r;

    sub_4a0e60(&field_ec, &s1, arg, &s2);
    sub_4a4d50(&field_1d5c, arg, &s1);
    r = sub_498f60();
    if (*(char*)((char*)r + 0xf5) != 0) {
        if (rc) {
            rc->v1();
        }
        sub_56c3b0(&s2);
        sub_4a3510(&field_1e18, 1);
        sub_56c0a0(&s1, 1, &s2, 0);
        if (rc) {
            old = _InterlockedExchangeAdd(&rc->refcount, -1);
            if (old == 1) {
                rc->v1();
                old = _InterlockedExchangeAdd((volatile long*)((char*)rc + 8), -1);
                if (old == 1) {
                    rc->v2();
                }
            }
        }
        if (p) {
            sub_5bfab0((char*)p + 8, &s1, &s2);
            sub_77e6d8();
            sub_77e6d8();
            sub_77e6d8();
            sub_4a3510(&field_1e18, 1);
            sub_5017c0(&s1, &s2, &s1, &s2, &s1, &s2);
            sub_77e698();
            sub_412dc0(&s1, &s2);
            sub_630b9e(&s1, &s2);
        }
        sub_77e6d8();
        sub_77e6d8();
        sub_4b4180(this, &s1, 1, &s2);
    } else {
        sub_4a63f0(this, &s1);
    }
    sub_630a1e();
}
