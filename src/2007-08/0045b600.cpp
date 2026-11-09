// from server: 22% by colin
struct Item {
    void construct();
    void setValue(int);
    void update();
};

struct RenderStatsItem : Item {
    void construct();
    void setValue(int);
    void update();
    void init();
};

void RenderStatsItem::init()
{
    construct();
    setValue(0);
    *(int*)((char*)this + 0x58) = 2;
    update();
    Item::update();
}
