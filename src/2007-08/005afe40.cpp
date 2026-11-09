// from server: 100% by colin
struct RotatePJoint {
    char pad[0xf8];
    void* field_f8;
    void setBaseAngle(float value);
};

void RotatePJoint::setBaseAngle(float value) {
    *(float*)((char*)field_f8 + 0x90) = value;
}
