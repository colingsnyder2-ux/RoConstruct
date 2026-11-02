// from server: 100% by tajop
struct Deleter {
    int value;
    Deleter() { value = 0; *(char*)&value = 0; }
};

struct Product {
    char storage[0xb4];
    Product();
};

struct SharedPtr {
    Product* px;
    void* pn;
    SharedPtr(Product* p, Deleter d);
};

struct Creator {
    static SharedPtr create();
};

SharedPtr Creator::create() {
    Deleter d;
    return SharedPtr(new Product(), d);
}
