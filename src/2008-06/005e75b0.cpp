// from server: 100% by tester
struct World { void wake(struct Prim*); };
struct Prim {
    char pad[0x58];
    World* world;
    char pad2[0xac - 0x5c];
    bool canSleep;
    void setCanSleep(bool b);
};
void Prim::setCanSleep(bool b) {
    if (b != canSleep) {
        canSleep = b;
        if (world) world->wake(this);
    }
}
