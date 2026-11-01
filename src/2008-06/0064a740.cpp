// from server: 100% by king_originala
struct Item;

struct Stage {
    virtual void unused();
    virtual int level();
    bool blocked(Item* item);
    bool eligible(Item* item);
};

struct Item {
    int padding0;
    Stage* stage;
    int padding1[4];
    int* state;
};

bool Stage::eligible(Item* item)
{
    if (item->stage) {
        int otherLevel = item->stage->level();
        if (otherLevel >= level() &&
            *item->state == 3 &&
            !blocked(item))
            return true;
    }
    return false;
}
