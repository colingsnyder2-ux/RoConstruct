// from server: 100% by colin
struct VWeld {
    char pad[0x100];
    void construct(int);
    VWeld* init(int);
};

VWeld* VWeld::init(int arg) {
    construct(arg);
    *(int*)((char*)this + 0x00) = 0x7b7a3c;
    *(int*)((char*)this + 0x04) = 0x7b7a34;
    *(int*)((char*)this + 0x10) = 0x7b7a2c;
    *(int*)((char*)this + 0x14) = 0x7b7a1c;
    *(int*)((char*)this + 0x2c) = 0x7b7a0c;
    *(int*)((char*)this + 0x44) = 0x7b79fc;
    *(int*)((char*)this + 0x5c) = 0x7b79ec;
    *(int*)((char*)this + 0x74) = 0x7b79dc;
    *(int*)((char*)this + 0x8c) = 0x7b79cc;
    *(int*)((char*)this + 0xe8) = 0x7b79b4;
    return this;
}
