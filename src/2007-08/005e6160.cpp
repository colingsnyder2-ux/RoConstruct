// from server: 100% by colin
struct Flag {
    char pad[0x168];
    void* field_168;
    void construct();
};

void Flag::construct() {
    *(int*)((char*)this + 0x00) = 0x7bd374;
    *(int*)((char*)this + 0x04) = 0x7bd36c;
    *(int*)((char*)this + 0x10) = 0x7bd364;
    *(int*)((char*)this + 0x14) = 0x7bd354;
    *(int*)((char*)this + 0x2c) = 0x7bd344;
    *(int*)((char*)this + 0x44) = 0x7bd334;
    *(int*)((char*)this + 0x5c) = 0x7bd324;
    *(int*)((char*)this + 0x74) = 0x7bd314;
    *(int*)((char*)this + 0x8c) = 0x7bd304;
    *(int*)((char*)this + 0xe8) = 0x7bd2fc;
    *(int*)((char*)this + 0x158) = 0x7bd2e4;
    void* p = *(void**)((char*)this + 0x168);
    int v = *(int*)((char*)p + 4);
    *(int*)((char*)this + v + 0x168) = 0x7bd2dc;
    void* q = *(void**)((char*)this + 0x168);
    int w = *(int*)((char*)q + 4);
    *(int*)((char*)this + w + 0x164) = w - 0xb8;
    extern void sub_5d2ba0();
    sub_5d2ba0();
}
