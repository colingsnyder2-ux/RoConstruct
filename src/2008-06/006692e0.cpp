// from server: 100% by king_originala
struct Item;
struct TreeStage;

struct Container {
    void remove(Item** item);
};

struct Owner {
    void remove(Item* item);
};

struct Item {
    virtual void release(unsigned int flags);
    TreeStage* parent;
    void detach(int stage);
};

struct TreeStage {
    virtual void release(unsigned int flags);
    virtual int rank();

    int reserved;
    Owner* owner;
    char padding[44];
    Container items;

    void remove(Item* item);
};

void TreeStage::remove(Item* item)
{
    Item* saved = item;
    *(Item* volatile*)&item = saved;
    items.remove(&item);

    if (saved->parent != 0) {
        int parentRank = saved->parent->rank();
        if (parentRank > rank())
            owner->remove(saved);
        saved->detach((int)this);
    }

    saved->release(1);
}
