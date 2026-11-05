// from server: 100% by tester
struct ConstraintAlign2Axes {
    char pad_0[0xcc];
    float baseAngle;
};

struct Joint {
    char pad_0[0xb4];
    ConstraintAlign2Axes* alignmentConstraint;

    float getBaseAngle();
};

float Joint::getBaseAngle() {
    return alignmentConstraint->baseAngle;
}