// from server: 60% by Intel
struct RBX_Motor6D {
    float getMotor6DValue();
};

float RBX_Motor6D::getMotor6DValue()
{
    float *p = (float *)((char *)this + 0xa8);
    return *p;
}
