// from server: 100% by colin
struct MotorJoint {
    char pad[0x88];
    float f88;
    float f8c;
    float f90;
    MotorJoint();
};

extern "C" void __stdcall sub_60a350();

MotorJoint::MotorJoint()
{
    sub_60a350();
    f88 = 0.0f;
    *(int*)this = 0x7b7e3c;
    f8c = 0.0f;
    f90 = 0.0f;
}
