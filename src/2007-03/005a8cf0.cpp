// from server: 100% by tester
struct RotatePJoint {
    char pad[0x110];
    void* ptr;
    void setBaseAngle(float value);
};

void RotatePJoint::setBaseAngle(float value) {
    *(float*)((char*)ptr + 0x8c) = value;
}