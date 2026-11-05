// from server: 100% by tester
struct EnumDescriptor {
    unsigned char pad[0x165];
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    bool get() const;
};

bool EnumDescriptor::get() const {
    return b1;
}