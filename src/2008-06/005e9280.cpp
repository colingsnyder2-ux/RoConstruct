// from server: 100% by king_originala
struct Item {
    virtual ~Item();
};

struct Container {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void remove(Item*);
};

struct S {
    char padding0[0x88];
    Container* container;
    char padding1[0x5c];
    int count;

    void remove(Item*);
};

void S::remove(Item* item)
{
    container->remove(item);
    if (item)
        delete item;
    --count;
}
