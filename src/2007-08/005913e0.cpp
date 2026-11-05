// from server: 100% by colin
struct RBX_BaseClass {
    void construct();
};

struct RBX_VObjectValue : RBX_BaseClass {
    RBX_VObjectValue* construct();
};

RBX_VObjectValue* RBX_VObjectValue::construct()
{
    RBX_BaseClass::construct();
    *(int*)((char*)this + 0x00) = 0x7afe34;
    *(int*)((char*)this + 0x04) = 0x7afe2c;
    *(int*)((char*)this + 0x10) = 0x7afe24;
    *(int*)((char*)this + 0x14) = 0x7afe14;
    *(int*)((char*)this + 0x2c) = 0x7afe04;
    *(int*)((char*)this + 0x44) = 0x7afdf4;
    *(int*)((char*)this + 0x5c) = 0x7afde4;
    *(int*)((char*)this + 0x74) = 0x7afdd4;
    *(int*)((char*)this + 0x8c) = 0x7afdc4;
    *(int*)((char*)this + 0xe8) = 0x7afdac;
    return this;
}
