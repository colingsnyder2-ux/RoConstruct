// from server: 50% by colin
struct S {
    char pad0[0xec];
    int field_ec;
    char pad1[0x294 - 0xec - 4];
    int field_294;
    int field_298;
    void sub_5ea500(int);
    S* ctor(int);
};

S* S::ctor(int arg) {
    int* p = (int*)field_298;
    int* q = (int*)p[1];
    *(int*)((char*)q + (int)this + 0x298) = 0x7a4ca4;
    field_294 = 0x7a4cac;
    sub_5ea500(arg);
    int* r = (int*)field_ec;
    *(int*)((char*)this + 0x00) = 0x7be274;
    *(int*)((char*)this + 0x04) = 0x7be26c;
    *(int*)((char*)this + 0x10) = 0x7be264;
    *(int*)((char*)this + 0x14) = 0x7be254;
    *(int*)((char*)this + 0x2c) = 0x7be244;
    *(int*)((char*)this + 0x44) = 0x7be234;
    *(int*)((char*)this + 0x5c) = 0x7be224;
    *(int*)((char*)this + 0x74) = 0x7be214;
    *(int*)((char*)this + 0x8c) = 0x7be204;
    *(int*)((char*)this + 0xe8) = 0x7be1f8;
    *(int*)((char*)this + 0x158) = 0x7be1e8;
    *(int*)((char*)this + 0x170) = 0x7be1dc;
    *(int*)((char*)this + 0x17c) = 0x7be1c4;
    int* s = (int*)r[1];
    *(int*)((char*)s + (int)this + 0xec) = 0x7be1b8;
    int* u = (int*)r[2];
    *(int*)((char*)u + (int)this + 0xec) = 0x7be1b0;
    int* w = (int*)r[3];
    *(int*)((char*)w + (int)this + 0xec) = 0x7be194;
    int* y = (int*)r[1];
    *(int*)((char*)y + (int)this + 0xe8) = (int)y - 0x198;
    int* aa = (int*)r[2];
    *(int*)((char*)aa + (int)this + 0xe8) = (int)aa - 0x1a0;
    int* ac = (int*)r[3];
    *(int*)((char*)ac + (int)this + 0xe8) = (int)ac - 0x1a8;
    return this;
}
