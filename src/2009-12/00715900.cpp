// from server: 76% by atomic.potato
struct RotatePJoint
{
    char pad0[180];
    float *m_value;
    void f(float value);
};

void RotatePJoint::f(float value)
{
    m_value[52] = value;
}
