// from server: 100% by tester
struct Inner {
    char pad[0x60];
    int* p;
};

struct PartInstance {
    char pad[0x1e0];
    Inner* inner;
    int* getValue();
};

int* PartInstance::getValue() {
    return reinterpret_cast<int*>(reinterpret_cast<char*>(inner->p) + 4);
}