// from server: 100% by colin
struct PartInstance;

struct Helper {
    void method(PartInstance* p);
};

struct PartInstance {
    char pad[0x1d8];
    Helper* helper;
    PartInstance* setSomething(PartInstance* p);
};

PartInstance* PartInstance::setSomething(PartInstance* p) {
    helper->method(p);
    return p;
}
