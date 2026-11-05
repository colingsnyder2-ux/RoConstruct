// from server: 27% by atomic.potato
extern "C" void __stdcall sub_425280(void*);
extern "C" void __stdcall sub_5a3740(void*);
extern "C" void* __stdcall sub_640a30(void*);
extern "C" void* __stdcall sub_4381b0();
extern "C" void __stdcall sub_80a052(void*, void*, void*);
extern "C" void __stdcall sub_80a04c(void*, void*, void*);
extern "C" void __stdcall sub_80a046(void*, void*);
extern "C" void __stdcall sub_80a040(void*, int);
extern "C" void __stdcall sub_80a03a(void*, float);
extern "C" bool __stdcall sub_7f8e00(void*, void*);
extern "C" void __stdcall sub_7f8c90(void*);
extern "C" void __stdcall sub_7f8e90(void*, void*);
extern "C" void* __stdcall sub_4f66a0();
extern "C" void* __stdcall sub_6e0810(void*, void*);
extern "C" void* __stdcall sub_6e08d0(void*, void*);

struct S {
    void* f0;
    char pad4[0x14];
    void* f18;
    void* f1c;
    void* f20;
    float f24;
    float f28;
    void func(void* a, void* b);
};

void S::func(void* a, void* b)
{
    f0 = a;
    void* p = sub_4f66a0();
    *(void**)((char*)this + 8) = p;
    *(char*)((char*)p + 0x19) = 1;
    void* q = *(void**)((char*)this + 8);
    *(void**)((char*)q + 4) = q;
    void* r = *(void**)((char*)this + 8);
    *(void**)r = r;
    void* s = *(void**)((char*)this + 8);
    *(void**)((char*)s + 8) = s;
    *(void**)((char*)this + 0xc) = 0;
    *(float*)((char*)this + 0x18) = *(float*)0xaa81b4;
    *(void**)((char*)this + 0x1c) = 0;
    *(void**)((char*)this + 0x20) = 0;
    *(float*)((char*)this + 0x24) = *(float*)0xa7fb50;
    *(float*)((char*)this + 0x28) = *(float*)0xa99898;
    void* t = sub_640a30(b);
    if (t != 0) {
        void* u = *(void**)((char*)t + 0x138);
        void* v = sub_6e0810((char*)u + 8, (char*)this + 0x14);
        if (sub_7f8e00((char*)this + 0x1c, v)) {
            sub_7f8c90((char*)this + 0x1c);
            sub_7f8e90((char*)this + 0x1c, v);
        }
        if (v != 0) {
            sub_425280((char*)v + 5);
        }
        void* w = sub_6e08d0((char*)u + 0xc, (char*)this + 0x14);
        if (sub_7f8e00((char*)this + 0x20, w)) {
            sub_7f8c90((char*)this + 0x20);
            sub_7f8e90((char*)this + 0x20, w);
        }
        if (w != 0) {
            sub_425280((char*)w + 5);
        }
        sub_80a052(f0, (void*)0xaa81a4, (char*)this + 0x14);
        sub_5a3740(*(void**)((char*)this + 0x14));
        sub_80a04c(f0, (void*)0xaa81a4, (char*)this + 0x10);
        sub_5a3740(*(void**)((char*)this + 0x10));
        void* x = sub_4381b0();
        sub_80a046(*(void**)((char*)this + 0x14), *(void**)((char*)x + 0xa8));
        sub_80a040(*(void**)((char*)this + 0x14), 2);
        void* y = sub_4381b0();
        float f = *(float*)((char*)y + 0xa4) * *(float*)0xa6ec60;
        sub_80a03a(*(void**)((char*)this + 0x10), f);
    }
}
