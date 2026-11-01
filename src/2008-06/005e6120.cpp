// from server: 100% by tester
struct Prim { char pad[0xac]; bool canSleep; };
struct It {
    Prim* p; int dir;
    void next();
};
struct Assembly {
    char pad[0x1c];
    Prim* head;
    bool computeCanSleep() const;
};
bool Assembly::computeCanSleep() const {
    It it;
    it.p = head;
    it.dir = 1;
    while (it.p) {
        if (!it.p->canSleep) return false;
        it.next();
    }
    return true;
}
