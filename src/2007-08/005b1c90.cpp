// from server: 100% by colin
struct VWeld {
    char pad[0x100];
    void construct(int);
    VWeld* init(int);
};

VWeld* VWeld::init(int arg) {
    construct(arg);
    *(int*)((char*)this + 0x00) = 0x7b73b4;
    *(int*)((char*)this + 0x04) = 0x7b73ac;
    *(int*)((char*)this + 0x10) = 0x7b73a4;
    *(int*)((char*)this + 0x14) = 0x7b7394;
    *(int*)((char*)this + 0x2c) = 0x7b7384;
    *(int*)((char*)this + 0x44) = 0x7b7374;
    *(int*)((char*)this + 0x5c) = 0x7b7364;
    *(int*)((char*)this + 0x74) = 0x7b7354;
    *(int*)((char*)this + 0x8c) = 0x7b7344;
    *(int*)((char*)this + 0xe8) = 0x7b732c;
    return this;
}
