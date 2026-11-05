// from server: 100% by king_originala
struct Interface {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual bool enabled() = 0;
};

struct Prefix {
    char padding[0x134];
};

struct VirtualBase {
    int value;
};

struct Target : Prefix, virtual VirtualBase {
    bool callback();
};

struct S {
    char padding[0x140];
    bool cached;
    bool dirty;
    Target* object;
    bool (Target::*callback)();

    Interface* getInterface();
    int f();
};

int S::f()
{
    if (getInterface()->enabled()) {
        if (dirty) {
            cached = (object->*callback)();
            dirty = false;
        }
        if (cached)
            return 1;
    }
    return 0;
}
