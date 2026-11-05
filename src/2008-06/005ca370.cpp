// from server: 100% by atomic.potato
struct Item
{
    int get() const;
    int pad0[3];
    int value;
};

int Item::get() const
{
    if (*(int*)((char*)this + 0xc) != 0)
        return *(int*)((char*)*(int*)((char*)this + 0xc) + 0x130);
    return 0;
}
