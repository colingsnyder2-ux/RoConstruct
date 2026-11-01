// from server: 100% by colin
struct TypedStatsItem {
    int getValue();
    void update(int);
};

struct TypedMemItem {
    void update();
};

void TypedMemItem::update()
{
    int v = ((TypedStatsItem*)((char*)this + 0x110))->getValue();
    ((TypedStatsItem*)this)->update(v);
}
