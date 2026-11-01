// from server: 100% by colin
struct ConstraintAlign2Axes {
    char pad_0[0x90];
    float baseAngle;
};

struct Joint {
    char pad_0[0xf8];
    ConstraintAlign2Axes* alignmentConstraint;

    float getBaseAngle();
};

float Joint::getBaseAngle() {
    return alignmentConstraint->baseAngle;
}
