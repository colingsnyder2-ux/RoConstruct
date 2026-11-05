// from server: 30% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl _invalid_parameter_noinfo();

struct RefCounted {
    void* vptr;
    volatile long ref1;
    volatile long ref2;
    void AddRef() {
        _InterlockedExchangeAdd(&ref1, 1);
    }
    void Release() {
        if (_InterlockedExchangeAdd(&ref1, -1) == 1) {
            ((void (__thiscall*)(RefCounted*))((void**)vptr)[1])(this);
            if (_InterlockedExchangeAdd(&ref2, -1) == 1) {
                ((void (__thiscall*)(RefCounted*))((void**)vptr)[2])(this);
            }
        }
    }
};

struct Vec3 { float x, y, z; };
struct Vec4 { float x, y, z, w; };

struct Inner {
    char pad0[0xc];
    void* begin;
    void* end;
};

struct Outer {
    char pad0[0x50];
    Inner* inner;
};

struct Widget {
    void* vptr;
    void* field4;
    char pad8[0x98];
    float f_a0;
    float f_a4;
    char pad_a8[0x14];
    char b_bc;
    char pad_bd[0x3];
    int i_c0;
    int i_c4;
    Vec4 v_c8;
    char pad_d8[0x4];
    Vec4 v_dc;

    void func(void* arg);
};

extern "C" void* __cdecl sub_70d570(void*, void*, void*);
extern "C" void* __cdecl sub_70d470(void*, void*, void*);
extern "C" void __cdecl sub_70e700(void*, void*);
extern "C" void __cdecl sub_657120(void*);
extern "C" void* __cdecl sub_559cb0();
extern "C" void* __cdecl sub_979de0();

extern float g_a126e4;
extern float g_a127d4;
extern float g_a1f624;
extern float g_a4c3d8;
extern float g_a4c3dc;
extern void* g_9ea90c;

void Widget::func(void* arg) {
    *(void**)this = arg;
    *(void**)((char*)this + 4) = *(void**)((char*)arg + 4);
    void* p = *(void**)((char*)arg + 4);
    if (p != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)p + 4), 1);
    }
    sub_657120(*(void**)((char*)this + 0x24));
    RefCounted* r = *(RefCounted**)((char*)this + 0x28);
    if (r != 0) {
        r->Release();
    }
    void* tmp;
    sub_70d570(&tmp, (void*)0xa4c408, (void*)0xa2d738);
    *(void**)this = *(void**)&tmp;
    *(void**)((char*)this + 4) = *(void**)((char*)&tmp + 4);
    void* p2 = *(void**)((char*)&tmp + 4);
    if (p2 != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)p2 + 4), 1);
    }
    sub_657120(*(void**)((char*)this + 0x24));
    RefCounted* r2 = *(RefCounted**)((char*)this + 0x28);
    if (r2 != 0) {
        r2->Release();
    }
    sub_70d470(&tmp, (void*)0xa008fe, (void*)0xa4c3f4);
    *(void**)this = *(void**)&tmp;
    *(void**)((char*)this + 4) = *(void**)((char*)&tmp + 4);
    void* p3 = *(void**)((char*)&tmp + 4);
    if (p3 != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)p3 + 4), 1);
    }
    sub_657120(*(void**)((char*)this + 0x24));
    RefCounted* r3 = *(RefCounted**)((char*)this + 0x28);
    if (r3 != 0) {
        r3->Release();
    }
    sub_70d570(&tmp, (void*)0xa4c3e0, (void*)0xa2d754);
    *(void**)this = *(void**)&tmp;
    *(void**)((char*)this + 4) = *(void**)((char*)&tmp + 4);
    void* p4 = *(void**)((char*)&tmp + 4);
    if (p4 != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)p4 + 4), 1);
    }
    sub_657120(*(void**)((char*)this + 0x24));
    RefCounted* r4 = *(RefCounted**)((char*)this + 0x28);
    if (r4 != 0) {
        r4->Release();
    }
    void* ebp = g_9ea90c;
    for (int i = 0; ; i++) {
        Outer* o = *(Outer**)((char*)this + 0x1c);
        if (o->inner == 0) break;
        Inner* in = o->inner;
        int count = (int)((char*)in->end - (char*)in->begin) >> 3;
        if ((unsigned)i >= (unsigned)count) break;
        if ((unsigned)i >= (unsigned)((int)((char*)in->end - (char*)in->begin) >> 3)) {
            ((void (__cdecl*)())ebp)();
        }
        void* elem = *(void**)((char*)in->begin + i * 8);
        void* src = elem ? (char*)elem + 0x2c : 0;
        void* out;
        sub_70e700(&out, src);
        Widget* w = (Widget*)out;
        w->i_c4 = 0xc;
        float f = (float)w->i_c4;
        w->f_a0 = f * g_a126e4;
        w->f_a4 = f * g_a127d4;
        void* v = sub_559cb0();
        w->v_c8.x = *(float*)v;
        w->v_c8.y = *(float*)((char*)v + 4);
        w->v_c8.z = *(float*)((char*)v + 8);
        w->v_c8.w = g_a1f624;
        void* v2 = sub_979de0();
        w->v_dc.x = *(float*)v2;
        w->v_dc.y = *(float*)((char*)v2 + 4);
        w->v_dc.z = *(float*)((char*)v2 + 8);
        w->v_dc.w = *(float*)((char*)v2 + 0xc);
        w->f_a0 = g_a4c3dc;
        w->f_a4 = g_a4c3d8;
        if (out != 0) {
            RefCounted* rr = (RefCounted*)out;
            rr->Release();
        }
    }
    *(char*)((char*)this + 0xbc) = 0;
    void* dst = *(void**)((char*)this + 0x5c);
    *(void**)dst = *(void**)((char*)this + 0x1c);
    *(void**)((char*)dst + 4) = *(void**)((char*)this + 0x20);
    void* p5 = *(void**)((char*)this + 0x20);
    if (p5 != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)p5 + 4), 1);
    }
    if (p5 != 0) {
        RefCounted* rr = (RefCounted*)p5;
        rr->Release();
    }
}
