// from server: 100% by colin
struct LocalBackpackItem
{
    LocalBackpackItem* construct();
};

extern "C" void __fastcall sub_005fcbc0(LocalBackpackItem* self);

LocalBackpackItem* LocalBackpackItem::construct()
{
    sub_005fcbc0(this);
    *(int*)((char*)this + 0x00) = 0x841364;
    *(int*)((char*)this + 0x10) = 0x841354;
    *(int*)((char*)this + 0x14) = 0x84134c;
    *(int*)((char*)this + 0x20) = 0x841344;
    *(int*)((char*)this + 0x24) = 0x841334;
    *(int*)((char*)this + 0x44) = 0x841324;
    *(int*)((char*)this + 0x64) = 0x841314;
    *(int*)((char*)this + 0x84) = 0x841304;
    *(int*)((char*)this + 0xa4) = 0x8412f4;
    *(int*)((char*)this + 0xc4) = 0x8412e4;
    *(int*)((char*)this + 0x130) = 0x8412dc;
    *(int*)((char*)this + 0x168) = 0x8412d0;
    *(int*)((char*)this + 0x16c) = 0x8412c4;
    *(int*)((char*)this + 0x170) = 0x8412b8;
    *(int*)((char*)this + 0x174) = 0x8412ac;
    *(int*)((char*)this + 0x178) = 0x8412a0;
    *(int*)((char*)this + 0x17c) = 0x841294;
    *(volatile int*)((char*)this + 0x180) = 0;
    *(int*)((char*)this + 0x184) = 0;
    *(int*)((char*)this + 0x188) = 0;
    *(int*)((char*)this + 0x18c) = 0;
    *(int*)((char*)this + 0x190) = 0;
    *(int*)((char*)this + 0x194) = 0;
    *(int*)((char*)this + 0x198) = 0;
    *(int*)((char*)this + 0x19c) = 0;
    *(int*)((char*)this + 0x1a0) = 0;
    *(int*)((char*)this + 0x1a4) = 0;
    *(int*)((char*)this + 0x1a8) = -1;
    *(int*)((char*)this + 0x160) = 1;
    return this;
}
