// from server: 70% by Intel
struct RBXDynamicRotateJoint {
    char pad[0xd0];
    void* field_d0;

    void sub_91fba0();
};

extern "C" void __stdcall sub_8ffe60();

void RBXDynamicRotateJoint::sub_91fba0() {
    void* ptr = field_d0;
    if (ptr) {
        sub_8ffe60();
    }
}
