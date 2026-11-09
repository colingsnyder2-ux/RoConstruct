// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
#include <math.h>

namespace RBX {
namespace Reflection { class PropertyDescriptor; }
extern Reflection::PropertyDescriptor prop_DesiredAngle;
extern Reflection::PropertyDescriptor prop_CurrentAngle;

class MotorJoint
{
    char pad[0xa4];
    float desiredAngle;
public:
    float getDesiredAngle() const { return desiredAngle; }
    void setDesiredAngle(float v) { desiredAngle = v; }
};

class Instance
{
public:
    void raisePropertyChanged(const Reflection::PropertyDescriptor& desc);
};

class Motor : public Instance
{
    char pad[0xac];
    MotorJoint* joint;
public:
    void setDesiredAngle(float value);
};

static inline bool fuzzyEq(float a, float b)
{
    return a == b || fabs(a - b) <= (fabs(a) + 1.0f) * 0.034906585f;
}

void Motor::setDesiredAngle(float value)
{
    MotorJoint* j = joint;
    float current = j->getDesiredAngle();
    if (value != current && !(fabs(value - current) <= (fabs(value) + 1.0f) * 0.034906585f)) {
        j->setDesiredAngle(value);
        raisePropertyChanged(prop_DesiredAngle);
        raisePropertyChanged(prop_CurrentAngle);
    }
}
}
