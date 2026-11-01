// from server: 100% by king_originala
struct TypedMemItem {
    void initializeBase();
    TypedMemItem* initialize(int value);
};

TypedMemItem* TypedMemItem::initialize(int value)
{
    initializeBase();
    *(int*)((char*)this + 0x158) = value;
    *(unsigned long*)((char*)this + 0x00) = 0x839f0c;
    *(unsigned long*)((char*)this + 0x10) = 0x839efc;
    *(unsigned long*)((char*)this + 0x14) = 0x839ef4;
    *(unsigned long*)((char*)this + 0x20) = 0x839eec;
    *(unsigned long*)((char*)this + 0x24) = 0x839edc;
    *(unsigned long*)((char*)this + 0x44) = 0x839ecc;
    *(unsigned long*)((char*)this + 0x64) = 0x839ebc;
    *(unsigned long*)((char*)this + 0x84) = 0x839eac;
    *(unsigned long*)((char*)this + 0xa4) = 0x839e9c;
    *(unsigned long*)((char*)this + 0xc4) = 0x839e8c;
    return this;
}
