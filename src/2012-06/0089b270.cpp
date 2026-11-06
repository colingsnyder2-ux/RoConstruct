// from server: 72% by tajop
struct PropDescriptor;
extern PropDescriptor desc_DesiredAngle;

struct MotorJoint
{
    char pad[0x98];
    float desiredAngle;
    void setDesiredAngle(float value);
};

struct MotorFeature
{
    char pad[0xa8];
    MotorJoint* joint;
    void raisePropertyChanged(const PropDescriptor& desc);
    void setDesiredAngle(float value);
};

void MotorFeature::setDesiredAngle(float value)
{
    if (value != joint->desiredAngle)
    {
        joint->setDesiredAngle(value);
        raisePropertyChanged(desc_DesiredAngle);
    }
}
