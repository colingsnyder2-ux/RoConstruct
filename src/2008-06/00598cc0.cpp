// from server: 100% by colin
struct PartInstance {
    char pad[0x2c8];
    void* primitive;
    float getMass() const;
};

float PartInstance::getMass() const {
    return *(float*)((char*)primitive + 0x8c);
}
