// from server: 45% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl malloc(unsigned int);
extern "C" void __cdecl free(void*);

struct Str {
    char pad[0x1c];
};

struct Vec {
    Str* begin;
    Str* end;
    Str* cap;
};

struct Inner {
    char pad0[4];
    void* arr;
    unsigned int cap;
    unsigned int size;
    unsigned int head;
};

struct Outer {
    Inner* p;
    char pad4[4];
    char pad8[0x18];
};

struct C {
    void* vt;
    void* ref;
    char pad8[0x18];
};

extern "C" void __stdcall sub_77e690(void*);
extern "C" void __stdcall sub_77e69c(void*);
extern "C" void __stdcall sub_77e6ac(void*);

void __stdcall sub_427920(void*);
void __stdcall sub_429e00();
void __stdcall sub_725750();
void __stdcall sub_725770();
void __stdcall sub_571500();
void __stdcall sub_41b830();
void __stdcall sub_41b6d0();
void __stdcall sub_62fc62(void*);
void* __cdecl sub_62fef6(unsigned int);

struct VDHTMLWindow_SignalDesc {
    void method(int, int, int, int, int, int, int, int);
};

void VDHTMLWindow_SignalDesc::method(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
    Vec v;
    v.begin = 0;
    v.end = 0;
    v.cap = 0;

    sub_427920(&v);
    sub_429e00();

    Outer* o = *(Outer**)this;
    void* q = (char*)o + 0x14;
    sub_725750();

    void* r = (char*)(*(Outer**)this) + 0x1c;
    sub_77e690(&r);

    Str* b = v.begin;
    Str* e = v.end;
    int n;
    if (b != 0) {
        n = 0;
    } else {
        n = (int)((char*)e - (char*)b) / 0x1c;
    }
    int cnt = n - 0xc;
    int idx = 0;
    int* sel = (cnt > 0) ? &cnt : &idx;
    int start = *sel;
    int off = start * 0x1c;

    while (b != 0) {
        int total = (int)((char*)e - (char*)b) / 0x1c;
        if ((unsigned)start >= (unsigned)total) break;

        Inner* in = *(Inner**)this;
        unsigned int sz = in->size + 1;
        if (in->cap <= sz) {
            sub_41b6d0();
        }
        unsigned int pos = in->head + in->size;
        if (in->cap <= pos) pos -= in->cap;
        if (in->arr == 0) {
        }
        void* slot = (void*)((char*)in->arr + pos * 4);
        if (*(void**)slot == 0) {
            *(void**)slot = sub_62fef6(0x1c);
        }
        void* obj = *(void**)slot;
        if (obj != 0) {
            sub_77e69c((char*)b + off);
        }
        in->size++;
        start++;
        off += 0x1c;
    }

    sub_725770();

    if (*(char*)((char*)this + 0x60) == 0) {
        sub_571500();
    } else {
        while (1) {
            C* c = *(C**)this;
            C tmp;
            tmp.vt = c->vt;
            tmp.ref = c->ref;
            if (tmp.ref != 0) {
                _InterlockedExchangeAdd((volatile long*)((char*)tmp.ref + 4), 1);
            }
            sub_41b830();
            if (*(int*)&tmp == 0) break;
        }
    }

    Str* bb = v.begin;
    if (bb != 0) {
        Str* ee = v.end;
        while (bb != ee) {
            sub_77e6ac(bb);
            bb = (Str*)((char*)bb + 0x1c);
        }
        free(v.begin);
    }
    v.begin = 0;
    v.end = 0;
    v.cap = 0;
    sub_77e6ac(&r);
}
