// from server: 27% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall sub_7F90E0(int, const char*, const char*, int, int, int, int);
extern "C" void __cdecl sub_80A058(void*);
extern "C" void __cdecl sub_7FC430(void*, void*, void*, void*);
extern "C" void __cdecl sub_611D00(void*, void*);
extern "C" void __cdecl sub_966FE0(void*, void*, void*, void*, int, void*);
extern "C" void __cdecl sub_640060(void*, int, void*);
extern "C" void __cdecl sub_8000E0(void*, void*);
extern "C" void __cdecl sub_606850(void*, void*);
extern "C" void __cdecl sub_603950();
extern "C" void* __cdecl sub_6071C0(void*);
extern "C" void* __cdecl sub_477270(void*);
extern "C" void __cdecl sub_5B0980(void*);
extern "C" void __cdecl sub_5B0830(void*, void*);
extern "C" void __cdecl sub_5A5930(void*, int);

struct Obj {
    char pad0[0x20];
    void* field20;
    char pad24[0x98 - 0x24];
    void* field98;
    char pad9c[0xa4 - 0x9c];
    void* fielda4;
    void* fielda8;
};

struct Vec {
    void* begin;
    void* end;
    void* cap;
};

struct S {
    void method(int);
};

void S::method(int arg) {
    Obj* self = (Obj*)this;
    if (*(volatile char*)0xccc395) {
        sub_7F90E0(3, (const char*)0xa9342c, (const char*)0xa92d80, 0x2eb, 0, 0, 0);
    }
    void* esi = self->field20;
    sub_603950();
    void* ecx = self->field20;
    void* eax;
    if (ecx != 0) {
        eax = sub_6071C0(ecx);
    } else {
        eax = 0;
    }
    void* ebx = 0;
    void* ebp = 0;
    void* edi = 0;
    void* p = eax;
    void* it = *(void**)((char*)p + 0xa4);
    void* end = *(void**)((char*)p + 0xa8);
    if (it != end) {
        do {
            void* obj = *(void**)it;
            char tmp[8];
            sub_8000E0((char*)obj + 0x2c, tmp);
            if (ebx == 0) {
                ebp = ebp;
            }
            it = (char*)it + 4;
        } while (it != end);
    }
    Vec v;
    v.begin = 0;
    v.end = 0;
    v.cap = 0;
    void* iter = ebx;
    if (ebx != ebp) {
        do {
            sub_606850(&v, iter);
            iter = (char*)iter + 8;
        } while (iter != ebp);
    }
    void* edx = self;
    void* edi2 = *(void**)((char*)edx + 0x98);
    void* ebx2 = v.end;
    void* esi2 = v.begin;
    sub_5B0980(edi2);
    if (esi2 != ebx2) {
        do {
            void* a = *(void**)esi2;
            sub_5B0830(edi2, a);
            esi2 = (char*)esi2 + 4;
        } while (esi2 != ebx2);
    }
    void* ecx2 = *(void**)((char*)self + 0x20);
    void* eax2;
    if (ecx2 != 0) {
        eax2 = sub_477270(ecx2);
    } else {
        eax2 = 0;
    }
    sub_5A5930(eax2, 8);
    void* eax3 = self;
    void* ecx3 = *(void**)((char*)eax3 + 0xc);
    void* eax4 = *(void**)((char*)eax3 + 4);
    if (*(int*)((char*)eax4 + 0x1c) >= 0x10) {
        eax4 = *(void**)((char*)eax4 + 8);
    } else {
        eax4 = (char*)eax4 + 8;
    }
    sub_611D00(eax4, ecx3);
    void* ecx4 = *(void**)((char*)self + 0x60);
    void** edx2 = *(void***)ecx4;
    void* eax5 = *edx2;
    ((void (*)(void*, int))eax5)(ecx4, 1);
    void* eax6 = v.begin;
    if (eax6 != 0) {
        sub_80A058(eax6);
    }
    v.begin = 0;
    v.end = 0;
    v.cap = 0;
    if (ebx != 0) {
        sub_7FC430(ebx, ebp, &v, self);
        sub_80A058(ebx);
    }
}
