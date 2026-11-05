// from server: 100% by king_originala
struct Item;

struct Stage {
    virtual void slot0();
    virtual int rank();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void forward(Item*);

    int reserved;
    Stage* next;

    void process(Item*, int);
};

struct Item {
    int reserved;
    Stage* stage;
};

void Stage::process(Item* item, int)
{
    if (item->stage->rank() > rank())
        next->forward(item);
}
