// from server: 100% by colin
struct FactoryProduct {
    char pad[0x100];
    FactoryProduct();
};

extern "C" void __fastcall sub_5d4870(void*);

FactoryProduct::FactoryProduct() {
    sub_5d4870(this);
    char* p = (char*)this;
    *(int*)(p + 0x00) = 0x7bb68c;
    *(int*)(p + 0x04) = 0x7bb680;
    *(int*)(p + 0x10) = 0x7bb678;
    *(int*)(p + 0x14) = 0x7bb668;
    *(int*)(p + 0x2c) = 0x7bb658;
    *(int*)(p + 0x44) = 0x7bb648;
    *(int*)(p + 0x5c) = 0x7bb638;
    *(int*)(p + 0x74) = 0x7bb628;
    *(int*)(p + 0x8c) = 0x7bb618;
    *(int*)(p + 0xe8) = 0x7bb610;
}
