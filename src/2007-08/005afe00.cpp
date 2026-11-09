// from server: 100% by colin
struct RotatePJoint {
    char pad[0xf8];
    void* field_f8;
    float getBaseAngle() const;
};

float RotatePJoint::getBaseAngle() const {
    return *(float*)((char*)field_f8 + 0x8c);
}
