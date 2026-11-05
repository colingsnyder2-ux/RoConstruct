// from server: 26% by atomic.potato
struct VPlayerBoundFuncDesc {
    char pad0[0x20];
    void* listHead;
    char pad24[0x2c - 0x24];
    int field2c;
    char pad30[0x9c];
    VPlayerBoundFuncDesc* ctor(int, int, int, int, int, int, int);
};

extern "C" void* __stdcall sub_52B6C0(int, int, int, int);
extern "C" void __cdecl sub_7E6900(void*, void*);
extern "C" void* __stdcall sub_6C1520();
extern "C" void* __stdcall sub_67F2E0(void*, void*);
extern "C" void __cdecl sub_7093D0(void*, void*);
extern "C" void* __cdecl sub_520A50(void*, void*, void*, void*);
extern "C" void __cdecl sub_5422B0(void*, int);
extern "C" void* __stdcall sub_6C11A0();

VPlayerBoundFuncDesc* VPlayerBoundFuncDesc::ctor(int a, int b, int c, int d, int e, int f, int g)
{
    void* p;
    void* q;
    void* r;
    void* s;
    void* t;
    void* u;
    int v;
    int w;
    char buf1[0x40];
    char buf2[0x40];
    char buf3[0x40];

    p = sub_52B6C0(a, b, c, d);
    sub_7E6900(this, p);
    this->field2c = e;
    *(void**)this = (void*)0xB70828;
    q = sub_6C1520();
    sub_67F2E0(q, buf1);
    sub_7093D0(buf2, buf1);
    r = this->listHead;
    s = sub_520A50(this, *(void**)((char*)r + 4), r, buf2);
    sub_5422B0(this, 1);
    *(void**)((char*)r + 4) = s;
    *(void**)((char*)s + 4) = s;
    t = sub_6C11A0();
    sub_67F2E0(t, buf3);
    sub_7093D0(buf3, buf3);
    u = *(void**)((char*)this + 0x24);
    v = *(int*)((char*)u + 4);
    w = (int)sub_520A50(this, (void*)v, u, buf3);
    sub_5422B0(this, 1);
    *(int*)((char*)u + 4) = w;
    *(int*)((char*)w + 4) = w;
    return this;
}
