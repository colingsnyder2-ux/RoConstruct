// from server: 100% by atomic.potato
struct PartInstance {
    char pad0[0xec];
    int field_ec;
    char pad1[0x158 - 0xec - 4];
    int field_158;
    int field_15c;
    char pad2[0x1d8 - 0x15c - 4];
    PartInstance* construct(int, int);
};

extern "C" int __stdcall sub_5bc2f0(int, int);

PartInstance* PartInstance::construct(int arg, int arg2) {
    if (arg2 != 0) {
        field_ec = 0x7b900c;
        field_158 = 0x7a4cd4;
        field_15c = 0x7a4ccc;
    }
    sub_5bc2f0(arg, 0);
    int* p = (int*)field_ec;
    *(int*)(this) = 0x7aa954;
    *(int*)((char*)this + 4) = 0x7aa948;
    *(int*)((char*)this + 0x10) = 0x7aa940;
    *(int*)((char*)this + 0x14) = 0x7aa930;
    *(int*)((char*)this + 0x2c) = 0x7aa920;
    *(int*)((char*)this + 0x44) = 0x7aa910;
    *(int*)((char*)this + 0x5c) = 0x7aa900;
    *(int*)((char*)this + 0x74) = 0x7aa8f0;
    *(int*)((char*)this + 0x8c) = 0x7aa8e0;
    *(int*)((char*)this + 0xe8) = 0x7aa8d4;
    int edx = *(int*)((char*)p + 4);
    *(int*)((char*)this + edx + 0xec) = 0x7aa8c8;
    int eax = field_ec;
    int ecx = *(int*)((char*)eax + 8);
    *(int*)((char*)this + ecx + 0xec) = 0x7aa8c0;
    return this;
}
