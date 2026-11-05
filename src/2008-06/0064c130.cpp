// from server: 100% by king_originala
struct SleepStage;

struct Item {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int query();

    int field4;
    int state;

    void f(int);
};

struct SleepStage {
    char padding[0xd0];
    int count;

    void remove(Item*);
    void change(Item*, int);
    void update(Item*, int);
    void process(Item*);
};

void SleepStage::process(Item* item)
{
    if (item->query() == 1) {
        if (item->state == 4 || item->state == 3)
            remove(item);

        if (item->state != 2)
            change(item, 2);

        --count;
        item->state = 0;
        item->f(reinterpret_cast<int>(this));
    } else if (item->state == 2) {
        remove(item);
        item->state = 0;
        item->f(reinterpret_cast<int>(this));
    } else {
        update(item, 2);
        item->state = 0;
        item->f(reinterpret_cast<int>(this));
    }
}
