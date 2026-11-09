// from server: 100% by colin
struct ConstraintAlign2Axes;

struct RotatePJoint {
    char pad[0xf8];
    ConstraintAlign2Axes* alignmentConstraint;
    void setBaseAngle(float value);
};

extern "C" void __fastcall ConstraintAlign2Axes_setBaseAngle(ConstraintAlign2Axes* self, float value);

void RotatePJoint::setBaseAngle(float value) {
    ConstraintAlign2Axes_setBaseAngle(alignmentConstraint, value);
}
