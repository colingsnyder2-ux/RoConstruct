// from server: 100% by king_originala
struct Owner {
    void reset(int value);
};

struct Ball {
    char pad[0x5c];
    int field_5c;
    char pad_60[0x40];
    Owner* owner;
    void setField(int value);
};

extern "C" Ball* __cdecl getChild(Ball* pane, int index);

struct Manager {
    void remove(Ball* pane);
    void update();
};

void Manager::remove(Ball* pane)
{
    Ball* child = getChild(pane, 0);
    while (child) {
        remove(child);
        update();
        child = getChild(pane, 0);
    }
    pane->owner->reset(0);
    pane->setField(0);
}
