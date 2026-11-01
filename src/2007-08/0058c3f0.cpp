// from server: 100% by colin
struct Stats_Item {
    void construct();
};

struct SoundServiceStatsItem : Stats_Item {
    SoundServiceStatsItem* construct();
};

SoundServiceStatsItem* SoundServiceStatsItem::construct()
{
    Stats_Item::construct();
    *(int*)((char*)this + 0) = 0x7af3cc;
    *(int*)((char*)this + 4) = 0x7af3c4;
    *(int*)((char*)this + 0x10) = 0x7af3bc;
    *(int*)((char*)this + 0x14) = 0x7af3ac;
    *(int*)((char*)this + 0x2c) = 0x7af39c;
    *(int*)((char*)this + 0x44) = 0x7af38c;
    *(int*)((char*)this + 0x5c) = 0x7af37c;
    *(int*)((char*)this + 0x74) = 0x7af36c;
    *(int*)((char*)this + 0x8c) = 0x7af35c;
    *(int*)((char*)this + 0xe8) = 0x7af350;
    return this;
}
