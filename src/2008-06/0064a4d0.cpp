// from server: 100% by king_originala
struct Item;

struct Stage {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void insert(Item*);

    int reserved;
    Stage* next;

    void process(Item*);
};

struct Item {
    char pad0[4];
    int m_x;
    int reserved8;
    void* first;
    void* second;

    void f(int);
};

void Stage::process(Item* item)
{
    item->f((int)this);
    if (item->first && item->second && item->first != item->second)
        next->insert(item);
}
