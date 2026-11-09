// from server: 26% by colin
struct SharedPtr {
    void* p;
    void* ctrl;
};

struct Obj {
    void** vtbl;
};

struct Inner {
    char pad[0xc];
    void* a;
    void* b;
    void* c;
};

struct S {
    char pad0[0xc];
    Inner inner;
    void f(SharedPtr* arg);
};

extern "C" {
    int __stdcall InterlockedDecrement(int*);
}

extern void* g_77d2e8;

void __stdcall sub_4d1860(void*, void*);
void __stdcall sub_457dd0(void*);
void __stdcall sub_4f4810(void*, void*, void*);
void __stdcall sub_4ef1a0(void*);
void __stdcall sub_4ef130(void*);
void __stdcall sub_4efdd0(void*, void*, void*, void*, void*, void*, void*);
void __stdcall sub_4920f0(void*);
void __stdcall sub_4f2000(void*, void*);
void __stdcall sub_40fac0(void*, void*);
void __stdcall sub_40fa90(void*, void*);

void S::f(SharedPtr* arg)
{
    Obj* o = *(Obj**)arg;
    SharedPtr sp1;
    sp1.p = 0;
    sp1.ctrl = 0;
    sub_4d1860((char*)o + 0x14, &sp1);
    bool b1 = (*(int*)sp1.p != 0);
    if (sp1.p) {
        int* r = (int*)((char*)sp1.p + 4);
        if (InterlockedDecrement(r) == 0) {
            sub_457dd0(sp1.p);
            if (sp1.p) {
                void** vt = *(void***)sp1.p;
                void (*fn)(void*, int) = (void (*)(void*, int))vt[0];
                fn(sp1.p, 1);
            }
        }
    }
    if (b1) return;

    Obj* o2 = *(Obj**)arg;
    void** vt2 = *(void***)o2;
    void (*fn2)(void*, SharedPtr*) = (void (*)(void*, SharedPtr*))vt2[6];
    SharedPtr sp2;
    sp2.p = 0;
    sp2.ctrl = 0;
    fn2(o2, &sp2);
    bool b2 = (*(int*)sp2.p == 0);
    if (sp2.p) {
        int* r = (int*)((char*)sp2.p + 4);
        if (InterlockedDecrement(r) == 0) {
            sub_457dd0(sp2.p);
            if (sp2.p) {
                void** vt = *(void***)sp2.p;
                void (*fn)(void*, int) = (void (*)(void*, int))vt[0];
                fn(sp2.p, 1);
            }
        }
    }
    if (b2) return;

    Obj* o3 = *(Obj**)arg;
    void** vt3 = *(void***)o3;
    void (*fn3)(void*, SharedPtr*) = (void (*)(void*, SharedPtr*))vt3[6];
    SharedPtr sp3;
    sp3.p = 0;
    sp3.ctrl = 0;
    fn3(o3, &sp3);
    void* inner = *(void**)sp3.p;
    SharedPtr sp4;
    sp4.p = 0;
    sp4.ctrl = 0;
    float one = 1.0f;
    sub_4f4810(inner, &sp4, &one);
    void* v = *(void**)sp4.p;
    bool b3 = (*(int*)((char*)v + 0x18) != 5);
    if (sp4.p) {
        int* r = (int*)((char*)sp4.p + 4);
        if (InterlockedDecrement(r) == 0) {
            sub_457dd0(sp4.p);
            if (sp4.p) {
                void** vt = *(void***)sp4.p;
                void (*fn)(void*, int) = (void (*)(void*, int))vt[0];
                fn(sp4.p, 1);
            }
        }
        sp4.p = 0;
    }
    if (sp3.p) {
        int* r = (int*)((char*)sp3.p + 4);
        if (InterlockedDecrement(r) == 0) {
            sub_457dd0(sp3.p);
            if (sp3.p) {
                void** vt = *(void***)sp3.p;
                void (*fn)(void*, int) = (void (*)(void*, int))vt[0];
                fn(sp3.p, 1);
            }
        }
    }
    if (b3) return;

    Obj* o4 = *(Obj**)arg;
    void** vt4 = *(void***)o4;
    void* (*fn4)(void*) = (void* (*)(void*))vt4[7];
    void* ebx = fn4(o4);
    void* esi = (char*)ebx + 0x24;
    sub_4ef1a0(esi);
    if (!(*(char*)&esi)) return;
    sub_4ef130(ebx);
    if (!(*(char*)&esi)) return;

    void* p1;
    void* p2;
    void* p3;
    sub_40fac0(&this->inner, &p1);
    void* edi = p1;
    sub_40fa90(&this->inner, &p2);
    void* ebx2 = p2;
    sub_40fac0(&this->inner, &p3);
    void* eax = p3;
    void* ecx1 = *(void**)((char*)edi + 4);
    void* edx1 = *(void**)edi;
    void* eax2 = *(void**)((char*)ebx2 + 4);
    void* ecx2 = *(void**)ebx2;
    SharedPtr sp5;
    sub_4efdd0(&sp5, eax, ecx2, eax2, edx1, ecx1, arg);
    sub_4920f0(&sp5);
    if (*(char*)&sp5) return;
    sub_4f2000(&this->inner, arg);
}
