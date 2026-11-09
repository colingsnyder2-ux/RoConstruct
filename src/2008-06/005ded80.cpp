// from server: 100% by colin
// from server: 91% by EspClaude
#pragma float_control(precise, off)
// roc 2008-06 005ded80  unit: RBX::Message  size: 134 bytes

extern "C" double __cdecl fabs(double);
extern "C" double __cdecl sqrt(double);
extern "C" double __cdecl atan(double);
#pragma intrinsic(fabs, sqrt, atan)

extern const float invalidResult;

float __cdecl f(float speed, float distance, float height, float gravity)
{
    double g = fabs(gravity);
    double disc = speed*speed*speed*speed
        - (distance*distance*g + 2.0*(speed*speed)*height)*g;

    if (disc <= 0.0)
        return invalidResult;

    double root = sqrt(disc);
    double v2 = speed*speed;
    double upper = atan((root + v2) / (distance*g));
    speed = (float)upper;
    double lower = atan((v2 - root) / (g*distance));
    gravity = (float)lower;

    const float* result = lower < upper ? &gravity : &speed;
    return *result;
}
