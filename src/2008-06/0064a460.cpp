// from server: 100% by king_originala
struct Item;

struct Stage {
    virtual ~Stage();
    virtual int level();
    virtual void slot2();
    virtual void slot3();
    virtual void insert(Item*);
    virtual void remove(Item*);

    int reserved;
    Stage* next;

    void process(Item*, int);
};

struct Item {
    int reserved0;
    Stage* stage;
    int reserved8;
    void* first;
    void* second;
};

void Stage::process(Item* item, int)
{
    if (item->first && item->second && item->first != item->second) {
        int value = item->stage->level();
        if (value <= level())
            next->insert(item);
    } else {
        int value = item->stage->level();
        if (value > level())
            next->remove(item);
    }
}
