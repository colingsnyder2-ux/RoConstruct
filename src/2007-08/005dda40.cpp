// from server: 100% by colin
struct EnumPropDescriptor {
    EnumPropDescriptor* init();
};

extern "C" void __fastcall base_init(EnumPropDescriptor* self);

EnumPropDescriptor* EnumPropDescriptor::init()
{
    base_init(this);
    char* p = (char*)this;
    *(int*)(p + 0) = 0x7bc444;
    *(int*)(p + 4) = 0x7bc438;
    *(int*)(p + 0x10) = 0x7bc430;
    *(int*)(p + 0x14) = 0x7bc420;
    *(int*)(p + 0x2c) = 0x7bc410;
    *(int*)(p + 0x44) = 0x7bc400;
    *(int*)(p + 0x5c) = 0x7bc3f0;
    *(int*)(p + 0x74) = 0x7bc3e0;
    *(int*)(p + 0x8c) = 0x7bc3d0;
    *(int*)(p + 0xe8) = 0x7bc3b8;
    return this;
}
