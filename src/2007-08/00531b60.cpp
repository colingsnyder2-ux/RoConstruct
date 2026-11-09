// from server: 100% by Yeetserama
struct FactoryProduct {
    char pad[0xec];
    int field_ec;
    char pad2[0x158 - 0xec - 4];
    int field_158;
    int field_15c;
    char pad3[0x1c];
    FactoryProduct* construct(int, int);
};

extern "C" int __stdcall sub_5318f0(int, int);

FactoryProduct* FactoryProduct::construct(int a, int b) {
    if (b != 0) {
        field_ec = 0x7b900c;
        field_158 = 0x7a4cd4;
        field_15c = 0x7a4ccc;
    }
    sub_5318f0(a, 0);
    *(int*)((char*)this + 0x00) = 0x7a5154;
    *(int*)((char*)this + 0x04) = 0x7a514c;
    *(int*)((char*)this + 0x10) = 0x7a5144;
    *(int*)((char*)this + 0x14) = 0x7a5134;
    *(int*)((char*)this + 0x2c) = 0x7a5124;
    *(int*)((char*)this + 0x44) = 0x7a5114;
    *(int*)((char*)this + 0x5c) = 0x7a5104;
    *(int*)((char*)this + 0x74) = 0x7a50f4;
    *(int*)((char*)this + 0x8c) = 0x7a50e4;
    *(int*)((char*)this + 0xe8) = 0x7a50d8;
    int* p = *(int**)((char*)this + 0xec);
    int* q = *(int**)((char*)p + 4);
    *(int*)((char*)q + (int)this + 0xec) = 0x7a50cc;
    int* r = *(int**)((char*)this + 0xec);
    int* s = *(int**)((char*)r + 8);
    *(int*)((char*)s + (int)this + 0xec) = 0x7a50c4;
    return this;
}
