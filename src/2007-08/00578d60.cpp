// from server: 100% by colin
struct BoundFuncDesc {
    char pad[0xec];
    int field_ec;
    char pad2[0x158 - 0xec - 4];
    int field_158;
    int field_15c;
    char pad3[0x1c];
    BoundFuncDesc* construct(int, int);
};

extern "C" int __stdcall sub_577c10(int, int);

BoundFuncDesc* BoundFuncDesc::construct(int a, int b) {
    if (b != 0) {
        field_ec = 0x7b900c;
        field_158 = 0x7a4cd4;
        field_15c = 0x7a4ccc;
    }
    sub_577c10(a, 0);
    *(int*)((char*)this + 0x00) = 0x7aaf7c;
    *(int*)((char*)this + 0x04) = 0x7aaf70;
    *(int*)((char*)this + 0x10) = 0x7aaf68;
    *(int*)((char*)this + 0x14) = 0x7aaf58;
    *(int*)((char*)this + 0x2c) = 0x7aaf48;
    *(int*)((char*)this + 0x44) = 0x7aaf38;
    *(int*)((char*)this + 0x5c) = 0x7aaf28;
    *(int*)((char*)this + 0x74) = 0x7aaf18;
    *(int*)((char*)this + 0x8c) = 0x7aaf08;
    *(int*)((char*)this + 0xe8) = 0x7aaefc;
    int* p = *(int**)((char*)this + 0xec);
    int* q = *(int**)((char*)p + 4);
    *(int*)((char*)q + (int)this + 0xec) = 0x7aaef0;
    int* r = *(int**)((char*)this + 0xec);
    int* s = *(int**)((char*)r + 8);
    *(int*)((char*)s + (int)this + 0xec) = 0x7aaee8;
    return this;
}
