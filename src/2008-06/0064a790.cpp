// from server: 100% by king_originala
extern bool disabled;

struct Item;
struct Clump;

struct Value {
    char data[12];
};

struct List {
    Item** items;
    int count;
};

struct Stage {
    virtual void slot0();
    virtual int level();

    bool process(Item*);
    int run(Clump*);
};

struct Item {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int kind();

    Stage* stage;
    int state;
    char padding[12];
    int* status;
};

struct Clump {
    char padding[104];
    bool enabled;
    bool dirty;
    char alignment[2];
    int adjustment;
    bool (__thiscall *evaluate)(void*);
    char* context;

    Value* getValue();
    Item* find(Item*);
};

int Stage::run(Clump* clump)
{
    if (disabled)
        goto inactive;

    if (clump->dirty) {
        clump->enabled =
            clump->evaluate(clump->context + clump->adjustment);
        clump->dirty = false;
    }

    if (!clump->enabled) {
inactive:
        return 3;
    }

    bool untouched = true;
    List* list = reinterpret_cast<List*>(clump->getValue());

    for (int i = 0; i < list->count; ++i) {
        Item* item = list->items[i];
        int itemLevel = item->stage->level();
        if (itemLevel < level())
            continue;

        int state = item->state;
        if (item->kind() == 1 && state != 3 && state != 4)
            continue;

        item = clump->find(item);
        if (!item->stage)
            continue;

        itemLevel = item->stage->level();
        if (itemLevel < level())
            continue;

        if (*item->status != 3)
            continue;

        untouched = false;
        if (process(item))
            return 3;
    }

    if (untouched)
        return 5;
    return 4;
}
