// from server: 100% by Intel
struct PartInstance {
    unsigned char getFlag();
};

unsigned char PartInstance::getFlag() {
    struct Inner {
        char pad[0x7C];
        unsigned char field_7C;
    };
    Inner* inner = *(Inner**)(reinterpret_cast<char*>(this) + 0x198);
    return inner->field_7C;
}
