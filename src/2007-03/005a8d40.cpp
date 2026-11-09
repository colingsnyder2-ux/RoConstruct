// from server: 100% by tester
struct RotatePJoint {
    char pad[0x110];
    void* field_f8;
    float getBaseAngle() const;
};

float RotatePJoint::getBaseAngle() const {
    return *(float*)((char*)field_f8 + 0x88);
}