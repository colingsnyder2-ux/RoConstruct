// from server: 100% by colin
struct VLocalBackpackItem {
    char pad0[0x8c];
    int m_8c;
    char pad1[0xe8 - 0x8c - 4];
    int m_e8;
    void sub_5d1110();
    VLocalBackpackItem* ctor();
};

VLocalBackpackItem* VLocalBackpackItem::ctor()
{
    sub_5d1110();
    *(int*)((char*)this + 0x00) = 0x7bacec;
    *(int*)((char*)this + 0x04) = 0x7bace0;
    *(int*)((char*)this + 0x10) = 0x7bacd8;
    *(int*)((char*)this + 0x14) = 0x7bacc8;
    *(int*)((char*)this + 0x2c) = 0x7bacb8;
    *(int*)((char*)this + 0x44) = 0x7baca8;
    *(int*)((char*)this + 0x5c) = 0x7bac98;
    *(int*)((char*)this + 0x74) = 0x7bac88;
    *(int*)((char*)this + 0x8c) = 0x7bac78;
    *(int*)((char*)this + 0xe8) = 0x7bac70;
    return this;
}
