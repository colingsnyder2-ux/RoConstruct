// from server: 100% by colin
struct Sky {
    char pad[0x94];
    int field_94;
    int field_98;
    char pad2[0x28];
    int field_c4;
    Sky* construct(int);
};

struct Helper {
    int method(int);
};

Sky* Sky::construct(int arg) {
    if (arg != 0) {
        field_98 = 0xa3fa70;
        field_c4 = 0xa3f838;
    }
    ((Helper*)this)->method(0);
    int v = field_98;
    *(int*)((char*)this + 0x00) = 0xa3f7ac;
    *(int*)((char*)this + 0x04) = 0xa3f7a0;
    *(int*)((char*)this + 0x18) = 0xa3f794;
    *(int*)((char*)this + 0x1c) = 0xa3f788;
    field_94 = 0xa3f780;
    *(int*)((char*)this + 0xa4) = 0xa3f76c;
    *(int*)((char*)this + 0xb0) = 0xa3f754;
    *(int*)((char*)this + 0xc0) = 0xa3f72c;
    int* p = *(int**)(v + 4);
    *(int*)((char*)p + (int)this + 0x98) = 0xa3f724;
    int v2 = field_98;
    int* p2 = *(int**)(v2 + 4);
    *(int*)((char*)p2 + (int)this + 0x94) = (int)p2 - 0x1f4;
    return this;
}
