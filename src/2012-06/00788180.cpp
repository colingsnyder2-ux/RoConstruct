// from server: 100% by tajop
struct Deleter {};

struct VCustomEvent {
    char pad[0x88];
    VCustomEvent();
};

struct SharedPtr {
    VCustomEvent* px;
    int* pn;
    SharedPtr(VCustomEvent* p, Deleter d);
    ~SharedPtr();
};

struct Creatable {
    static SharedPtr create();
};

SharedPtr Creatable::create() {
    return SharedPtr(new VCustomEvent, Deleter());
}
