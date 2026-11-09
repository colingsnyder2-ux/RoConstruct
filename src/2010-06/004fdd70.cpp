// from server: 100% by tester
struct IdSerializer {
    unsigned short value;
    bool equals(const IdSerializer* other) const;
};

bool IdSerializer::equals(const IdSerializer* other) const {
    return value == other->value;
}
