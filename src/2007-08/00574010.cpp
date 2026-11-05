// from server: 100% by colin
struct Inner {
    char pad[0x60];
    int* p;
};

struct PartInstance {
    char pad[0x1d8];
    Inner* inner;
    int* getValue();
};

int* PartInstance::getValue() {
    return reinterpret_cast<int*>(reinterpret_cast<char*>(inner->p) + 4);
}
