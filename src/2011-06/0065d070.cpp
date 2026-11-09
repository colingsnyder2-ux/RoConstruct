// from server: 100% by tester
struct TypedStatsItem {
    int getValue();
    void update(int);
};

struct TypedMemItem {
    void update();
};

void TypedMemItem::update()
{
    int v = ((TypedStatsItem*)((char*)this + 0xb8))->getValue();
    ((TypedStatsItem*)this)->update(v);
}
