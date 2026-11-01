// from server: 100% by colin
struct RotatePJoint {
    char pad[0xf8];
    void* ptr;
    float getBaseAngle() const;
};

float RotatePJoint::getBaseAngle() const {
    return *(float*)((char*)ptr + 0x88);
}
