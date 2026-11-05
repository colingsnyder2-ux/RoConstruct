// from server: 100% by tester
struct PartInstance {
    unsigned char getFlag();
};

unsigned char PartInstance::getFlag() {
    struct Inner {
        char pad[0x7c];
        unsigned char field_7C;
    };
    Inner* inner = *(Inner**)(reinterpret_cast<char*>(this) + 0x168);
    return inner->field_7C;
}