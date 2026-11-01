// from server: 100% by colin
struct RotatePJoint {
    char pad[0xf8];
    void* ptr;
    void setBaseAngle(float value);
};

void RotatePJoint::setBaseAngle(float value) {
    *(float*)((char*)ptr + 0x8c) = value;
}
