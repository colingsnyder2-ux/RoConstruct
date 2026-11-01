// from server: 100% by colin
struct Base {
    void init();
};

struct S : Base {
    S* construct();
};

S* S::construct() {
    init();
    *(int*)((char*)this + 0x00) = 0x7b24bc;
    *(int*)((char*)this + 0x04) = 0x7b24b0;
    *(int*)((char*)this + 0x10) = 0x7b24a8;
    *(int*)((char*)this + 0x14) = 0x7b2498;
    *(int*)((char*)this + 0x2c) = 0x7b2488;
    *(int*)((char*)this + 0x44) = 0x7b2478;
    *(int*)((char*)this + 0x5c) = 0x7b2468;
    *(int*)((char*)this + 0x74) = 0x7b2458;
    *(int*)((char*)this + 0x8c) = 0x7b2448;
    *(int*)((char*)this + 0xe8) = 0x7b2440;
    return this;
}
