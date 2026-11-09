// from server: 100% by colin
struct FactoryProduct {
    char pad[0xb4];
    FactoryProduct* construct();
};

extern "C" void __fastcall base_construct(void*);

FactoryProduct* FactoryProduct::construct() {
    base_construct(this);
    *(int*)((char*)this + 0x00) = 0xb9ffac;
    *(int*)((char*)this + 0x04) = 0xb9ffa4;
    *(int*)((char*)this + 0x18) = 0xb9ff98;
    *(int*)((char*)this + 0x1c) = 0xb9ff8c;
    *(int*)((char*)this + 0x80) = 0xb9ff84;
    *(int*)((char*)this + 0xb0) = 1;
    *(int*)((char*)this + 0xac) = 4;
    return this;
}
