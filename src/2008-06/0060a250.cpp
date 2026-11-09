// from server: 100% by tester
struct PartInstance {
    char pad[0x150];
    void* primitive;
    float getMass() const;
};

float PartInstance::getMass() const {
    return *(float*)((char*)primitive + 0x94);
}