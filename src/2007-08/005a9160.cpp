// from server: 100% by colin
struct Stage {
    virtual int getStage();
    virtual int getOther();
    char pad[4];
    Stage* next;
};

struct World {
    char pad[0x34];
    Stage* stage;
    Stage* getStage();
};

Stage* World::getStage() {
    Stage* s = stage;
    while (s->getOther() != 4) {
        s = s->next;
    }
    return s;
}
