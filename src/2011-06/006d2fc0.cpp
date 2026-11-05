// from server: 76% by atomic.potato
struct RotatePJoint {
    char pad_0[0xb4];
    void* field_b4;

    void setValue(float value);
};

void RotatePJoint::setValue(float value) {
    *(float*)((char*)field_b4 + 0xcc) = value;
}
