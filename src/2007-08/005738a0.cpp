// from server: 100% by colin
struct PartInstance {
    char pad[0xec];
    void* field_ec;
    void construct();
};

void PartInstance::construct()
{
    void* p = field_ec;
    *(int*)((char*)this + 0x00) = 0x7aa954;
    *(int*)((char*)this + 0x04) = 0x7aa948;
    *(int*)((char*)this + 0x10) = 0x7aa940;
    *(int*)((char*)this + 0x14) = 0x7aa930;
    *(int*)((char*)this + 0x2c) = 0x7aa920;
    *(int*)((char*)this + 0x44) = 0x7aa910;
    *(int*)((char*)this + 0x5c) = 0x7aa900;
    *(int*)((char*)this + 0x74) = 0x7aa8f0;
    *(int*)((char*)this + 0x8c) = 0x7aa8e0;
    *(int*)((char*)this + 0xe8) = 0x7aa8d4;
    void* q = *(void**)((char*)p + 4);
    *(int*)((char*)q + (int)this + 0xec) = 0x7aa8c8;
    void* r = *(void**)((char*)field_ec + 8);
    *(int*)((char*)r + (int)this + 0xec) = 0x7aa8c0;
    extern void __stdcall sub_5bb520();
    sub_5bb520();
}
