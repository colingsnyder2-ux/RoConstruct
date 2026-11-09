// from server: 100% by atomic.potato
struct RotatePJoint {
    char pad0[180];
    float *m_value;
    float f();
};

float RotatePJoint::f()
{
    return m_value[39];
}
