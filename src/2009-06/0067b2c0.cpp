// from server: 100% by why2
struct RBX_RotatePJoint {
    char pad[0xac];
    void* ptr;
    float getValue();
};

float RBX_RotatePJoint::getValue() {
    return *(float*)((char*)ptr + 0x9c);
}
