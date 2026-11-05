// from server: 100% by tester
struct PartInstance;

struct Helper {
    void method(PartInstance* p);
};

struct PartInstance {
    char pad[0x198];
    Helper* helper;
    PartInstance* setSomething(PartInstance* p);
};

PartInstance* PartInstance::setSomething(PartInstance* p) {
    helper->method(p);
    return p;
}
