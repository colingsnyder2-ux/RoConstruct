// from server: 100% by atomic.potato
struct BackpackItem {
    BackpackItem();
    BackpackItem* construct();
};

BackpackItem* BackpackItem::construct()
{
    this->BackpackItem::BackpackItem();
    *(int*)((char*)this + 0x00) = 0x7b206c;
    *(int*)((char*)this + 0x04) = 0x7b2060;
    *(int*)((char*)this + 0x10) = 0x7b2058;
    *(int*)((char*)this + 0x14) = 0x7b2048;
    *(int*)((char*)this + 0x2c) = 0x7b2038;
    *(int*)((char*)this + 0x44) = 0x7b2028;
    *(int*)((char*)this + 0x5c) = 0x7b2018;
    *(int*)((char*)this + 0x74) = 0x7b2008;
    *(int*)((char*)this + 0x8c) = 0x7b1ff8;
    *(int*)((char*)this + 0xe8) = 0x7b1ff0;
    return this;
}
