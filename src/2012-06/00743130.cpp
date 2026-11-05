// from server: 100% by atomic.potato
struct Inner {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void Target(int arg, int arg2);
};

struct Holder {
    char pad[0x9c];
    Inner inner;
};

struct PartTool {
    char pad[0x30];
    Holder* h;
    void DoIt(int arg);
};

void PartTool::DoIt(int arg) {
    Holder* hp = this->h;
    if (hp) {
        hp->inner.Target(arg, 0);
    }
}
