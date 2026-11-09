// from server: 100% by colin
struct LocalBackpackItem {
    char pad0[0xec];
    void construct();
    LocalBackpackItem* init();
};

extern "C" void __stdcall sub_0059cf50();

LocalBackpackItem* LocalBackpackItem::init()
{
    construct();
    *(int*)((char*)this + 0x00) = 0x7ba7ec;
    *(int*)((char*)this + 0x04) = 0x7ba7e0;
    *(int*)((char*)this + 0x10) = 0x7ba7d8;
    *(int*)((char*)this + 0x14) = 0x7ba7c8;
    *(int*)((char*)this + 0x2c) = 0x7ba7b8;
    *(int*)((char*)this + 0x44) = 0x7ba7a8;
    *(int*)((char*)this + 0x5c) = 0x7ba798;
    *(int*)((char*)this + 0x74) = 0x7ba788;
    *(int*)((char*)this + 0x8c) = 0x7ba778;
    *(int*)((char*)this + 0xe8) = 0x7ba770;
    return this;
}
