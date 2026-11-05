// from server: 100% by tester
struct Inner {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void dispatch(int);
};

struct Outer {
    char pad[0x34];
    Inner* member;
    void fire();
};

void Outer::fire() {
    member->dispatch(0);
}
