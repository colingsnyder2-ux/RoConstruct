// from server: 94% by atomic.potato
struct Item
{
    int f();
};

int Item::f()
{
    if (*(unsigned char*)this)
        return 1;
    return -(int)*(unsigned char*)((char*)this + 1);
}
