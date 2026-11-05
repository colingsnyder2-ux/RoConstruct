// from server: 100% by why2
struct RBX_RotatePJoint {
    char pad[0xac];
    void* ptr;
    float get() const;
};

float RBX_RotatePJoint::get() const {
    return *(float*)((char*)ptr + 0xa0);
}
