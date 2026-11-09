// from server: 100% by colin
struct VWeld {
    char pad[0x100];
    void construct(int);
    VWeld* init(int);
};

VWeld* VWeld::init(int arg) {
    construct(arg);
    *(int*)((char*)this + 0x00) = 0x7b7b0c;
    *(int*)((char*)this + 0x04) = 0x7b7b04;
    *(int*)((char*)this + 0x10) = 0x7b7afc;
    *(int*)((char*)this + 0x14) = 0x7b7aec;
    *(int*)((char*)this + 0x2c) = 0x7b7adc;
    *(int*)((char*)this + 0x44) = 0x7b7acc;
    *(int*)((char*)this + 0x5c) = 0x7b7abc;
    *(int*)((char*)this + 0x74) = 0x7b7aac;
    *(int*)((char*)this + 0x8c) = 0x7b7a9c;
    *(int*)((char*)this + 0xe8) = 0x7b7a84;
    return this;
}
