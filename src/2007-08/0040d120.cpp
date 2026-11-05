// from server: 100% by colin
struct CGdiObject {
    CGdiObject* construct();
};

extern "C" void __fastcall sub_555C70(CGdiObject* self);

CGdiObject* CGdiObject::construct() {
    sub_555C70(this);
    *(int*)((char*)this + 0x00) = 0x7865ac;
    *(int*)((char*)this + 0x04) = 0x7865a4;
    *(int*)((char*)this + 0x10) = 0x78659c;
    *(int*)((char*)this + 0x14) = 0x78658c;
    *(int*)((char*)this + 0x2c) = 0x78657c;
    *(int*)((char*)this + 0x44) = 0x78656c;
    *(int*)((char*)this + 0x5c) = 0x78655c;
    *(int*)((char*)this + 0x74) = 0x78654c;
    *(int*)((char*)this + 0x8c) = 0x78653c;
    *(int*)((char*)this + 0xe8) = 0x786534;
    return this;
}
