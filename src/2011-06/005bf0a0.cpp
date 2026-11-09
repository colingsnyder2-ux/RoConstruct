// from server: 75% by atomic.potato
extern "C" void* __cdecl sub_4D0090(unsigned int);
extern "C" void __cdecl sub_602AB0(void*);

struct Inner {
    void* f0;
    void* f4;
    void* f8;
    char padC[4];
    void* f10;
    void* f14;
    char pad18[8];
    void* f20;
    void* f24;
};

struct Outer {
    void* f0;
    void* f4;
    void* f8;
    char padC[0x10];
    void* f1C;
};

struct S {
    char pad0[0x1C];
    void* f1C;
    void method(Outer* a, void* b);
};

void S::method(Outer* a, void* b)
{
    void* g = *(void**)0xccb7a8;
    Inner* p = (Inner*)sub_4D0090(0x28);
    if (p != 0) {
        p->f0 = 0;
        p->f4 = 0;
        p->f8 = 0;
        p->f10 = g;
        p->f14 = 0;
        p->f20 = 0;
        p->f24 = 0;
    } else {
        p = 0;
    }
    if (a->f8 == 0) {
        a->f4 = p;
    } else {
        *(void**)a->f8 = p;
    }
    a->f8 = p;
    void* vt = *(void**)this->f1C;
    void* fn = *(void**)((char*)vt + 8);
    void* tmp;
    ((void (__thiscall*)(void*, void**, void*))fn)(this->f1C, &tmp, b);
    void* r = tmp;
    char* q = (char*)p + 0x10;
    sub_602AB0(q);
    *(void**)(q + 8) = r;
    *(int*)(q + 4) = 5;
}
