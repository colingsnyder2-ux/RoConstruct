// from server: 100% by why2
struct RBX_RotatePJoint {
    char pad[0xac];
    void* ptr;
    void setValue(float value);
};

void RBX_RotatePJoint::setValue(float value) {
    *(float*)((char*)ptr + 0xd0) = value;
}
