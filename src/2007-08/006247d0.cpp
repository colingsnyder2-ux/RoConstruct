// from server: 1% by colin
struct Cofm {
    char pad[0x14];
    float mass;
    float getMass() const;
};

float Cofm::getMass() const {
    return mass;
}
