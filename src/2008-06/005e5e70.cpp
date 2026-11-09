// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
extern "C" double __cdecl fabs(double);
#pragma intrinsic(fabs)

struct MotorJoint {
    char padding[0x8c];
    float current;
    float velocity;
    float desired;

    void setCurrent(float value);
    void step(float);
};

void MotorJoint::step(float)
{
    double speed = fabs(velocity);
    double delta = (double)desired - current;

    if (fabs(delta) < speed)
        setCurrent(desired);
    else if (delta > 0.0)
        setCurrent((float)(current + speed));
    else
        setCurrent((float)(current - speed));
}
