// from server: 58% by colin
struct S {
    char pad[0x2d8];
    void* field_2d8;
    void* field_2c4;
    void* field_2cc;
    void* field_2d4;
    void* field_ec;
    void* field_e8;
    void* field_158;
    void* field_170;
    void* field_17c;
    int field_284;
    int field_288;
    char field_28c;
    char field_290;
    int field_298;
    int field_29c;
    char field_2a0;
    char field_2a4;
    int field_2a8;
    int field_2ac;
    char field_2b0;
    double field_2b8;
    void construct(int);
};

extern "C" {
    void __stdcall string_ctor(void*, const char*);
    void __stdcall string_dtor(void*);
}

void S::construct(int arg)
{
    if (arg != 0) {
        *(void**)((char*)this + 0xec) = (void*)0x7c23a0;
        *(void**)((char*)this + 0x2d8) = (void*)0x7aafe8;
        *(void**)((char*)this + 0x2c4) = (void*)0x7a4cd4;
        *(void**)((char*)this + 0x2cc) = (void*)0x7a4ccc;
        void* p = *(void**)((char*)this + 0x2d8);
        *(void**)((char*)this + 0x2d4) = (void*)0x7a4cac;
        void* q = *(void**)((char*)p + 4);
        *(void**)((char*)q + (int)this + 0x2d8) = (void*)0x7a4ca4;
    }
    ((void (__thiscall*)(S*, int))0x5facb0)(this, 0);
    void* r = *(void**)((char*)this + 0xec);
    *(void**)this = (void*)0x7c2334;
    *(void**)((char*)this + 4) = (void*)0x7c232c;
    *(void**)((char*)this + 0x10) = (void*)0x7c2324;
    *(void**)((char*)this + 0x14) = (void*)0x7c2314;
    *(void**)((char*)this + 0x2c) = (void*)0x7c2304;
    *(void**)((char*)this + 0x44) = (void*)0x7c22f4;
    *(void**)((char*)this + 0x5c) = (void*)0x7c22e4;
    *(void**)((char*)this + 0x74) = (void*)0x7c22d4;
    *(void**)((char*)this + 0x8c) = (void*)0x7c22c4;
    *(void**)((char*)this + 0xe8) = (void*)0x7c22b8;
    *(void**)((char*)this + 0x158) = (void*)0x7c22a8;
    *(void**)((char*)this + 0x170) = (void*)0x7c229c;
    *(void**)((char*)this + 0x17c) = (void*)0x7c2284;
    void* s = *(void**)((char*)r + 4);
    *(void**)((char*)s + (int)this + 0xec) = (void*)0x7c2278;
    void* t = *(void**)((char*)this + 0xec);
    void* u = *(void**)((char*)t + 8);
    *(void**)((char*)u + (int)this + 0xec) = (void*)0x7c2270;
    void* v = *(void**)((char*)this + 0xec);
    void* w = *(void**)((char*)v + 0xc);
    *(void**)((char*)w + (int)this + 0xec) = (void*)0x7c2254;
    void* x = *(void**)((char*)this + 0xec);
    void* y = *(void**)((char*)x + 4);
    *(void**)((char*)y + (int)this + 0xe8) = (void*)((char*)y - 0x1d8);
    void* z = *(void**)((char*)this + 0xec);
    void* aa = *(void**)((char*)z + 8);
    *(void**)((char*)aa + (int)this + 0xe8) = (void*)((char*)aa - 0x1e0);
    void* ab = *(void**)((char*)this + 0xec);
    void* ac = *(void**)((char*)ab + 0xc);
    *(void**)((char*)ac + (int)this + 0xe8) = (void*)((char*)ac - 0x1e8);
    *(int*)((char*)this + 0x284) = 0;
    *(int*)((char*)this + 0x288) = 0;
    *(char*)((char*)this + 0x28c) = 0;
    *(char*)((char*)this + 0x290) = 0;
    *(int*)((char*)this + 0x298) = 0;
    *(int*)((char*)this + 0x29c) = 0;
    *(char*)((char*)this + 0x2a0) = 0;
    *(char*)((char*)this + 0x2a4) = 0;
    *(int*)((char*)this + 0x2a8) = 0;
    *(int*)((char*)this + 0x2ac) = 0;
    *(double*)((char*)this + 0x2b8) = 0.0;
    *(char*)((char*)this + 0x2b0) = 0;
    char buf[0x1c];
    string_ctor(buf, "CFrame");
    ((void (__thiscall*)(S*, void*))0x541bf0)(this, buf);
    string_dtor(buf);
}
