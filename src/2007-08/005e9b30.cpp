// from server: 71% by colin
struct S {
    char pad[0x298];
    void* field_298;
    void* field_294;
    void* field_ec;
    void* field_e8;
    void* field_158;
    void* field_170;
    void* field_17c;
    void* field_8c;
    void* field_74;
    void* field_5c;
    void* field_44;
    void* field_2c;
    void* field_14;
    void* field_10;
    void* field_4;
    void* field_0;
    void method(int);
};

extern "C" void __stdcall sub_578ed0(void*, int);

void S::method(int arg) {
    void* p = field_298;
    field_294 = (void*)0x7a4cac;
    void* q = *(void**)((char*)p + 4);
    *(void**)((char*)q + (int)this + 0x298) = (void*)0x7a4ca4;
    *(int*)((char*)this + 0x14) = arg;
    *(int*)((char*)this + 4) = 1;
    sub_578ed0(this, arg);
    void* r = field_ec;
    *(void**)this = (void*)0x7bdd74;
    *(void**)((char*)this + 4) = (void*)0x7bdd68;
    *(void**)((char*)this + 0x10) = (void*)0x7bdd60;
    *(void**)((char*)this + 0x14) = (void*)0x7bdd50;
    *(void**)((char*)this + 0x2c) = (void*)0x7bdd40;
    *(void**)((char*)this + 0x44) = (void*)0x7bdd30;
    *(void**)((char*)this + 0x5c) = (void*)0x7bdd20;
    *(void**)((char*)this + 0x74) = (void*)0x7bdd10;
    *(void**)((char*)this + 0x8c) = (void*)0x7bdd00;
    *(void**)((char*)this + 0xe8) = (void*)0x7bdcf4;
    *(void**)((char*)this + 0x158) = (void*)0x7bdce4;
    *(void**)((char*)this + 0x170) = (void*)0x7bdcd8;
    *(void**)((char*)this + 0x17c) = (void*)0x7bdcc0;
    void* s = *(void**)((char*)r + 4);
    *(void**)((char*)s + (int)this + 0xec) = (void*)0x7bdcb4;
    void* t = field_ec;
    void* u = *(void**)((char*)t + 8);
    *(void**)((char*)u + (int)this + 0xec) = (void*)0x7bdcac;
    void* v = field_ec;
    void* w = *(void**)((char*)v + 0xc);
    *(void**)((char*)w + (int)this + 0xec) = (void*)0x7bdc90;
    void* x = field_ec;
    void* y = *(void**)((char*)x + 4);
    *(void**)((char*)y + (int)this + 0xe8) = (void*)((char*)y - 0x198);
    void* z = field_ec;
    void* a = *(void**)((char*)z + 8);
    *(void**)((char*)a + (int)this + 0xe8) = (void*)((char*)a - 0x1a0);
    void* b = field_ec;
    void* c = *(void**)((char*)b + 0xc);
    *(void**)((char*)c + (int)this + 0xe8) = (void*)((char*)c - 0x1a8);
}
