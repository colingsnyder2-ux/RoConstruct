// from server: 100% by why2
struct EnumDescriptor {
    bool equals(const EnumDescriptor& other) const;
};

bool EnumDescriptor::equals(const EnumDescriptor& other) const {
    return this != &other;
}
