// from server: 100% by colin
struct EnumDescriptor {
    unsigned char pad[0x11d];
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    bool get() const;
};

bool EnumDescriptor::get() const {
    return b1;
}
