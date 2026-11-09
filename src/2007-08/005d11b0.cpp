// from server: 100% by colin
struct FactoryProduct {
    char pad[0x100];
    FactoryProduct* init();
};

extern "C" void __fastcall sub_5d1040(void*);

FactoryProduct* FactoryProduct::init() {
    sub_5d1040(this);
    char* p = (char*)this;
    *(int*)(p + 0x00) = 0x7babec;
    *(int*)(p + 0x04) = 0x7babe0;
    *(int*)(p + 0x10) = 0x7babd8;
    *(int*)(p + 0x14) = 0x7babc8;
    *(int*)(p + 0x2c) = 0x7babb8;
    *(int*)(p + 0x44) = 0x7baba8;
    *(int*)(p + 0x5c) = 0x7bab98;
    *(int*)(p + 0x74) = 0x7bab88;
    *(int*)(p + 0x8c) = 0x7bab78;
    *(int*)(p + 0xe8) = 0x7bab70;
    return this;
}
