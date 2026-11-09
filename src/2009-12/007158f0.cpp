// from server: 100% by atomic.potato
struct RotatePJoint {
    char pad0[180];
    float *m_value;
    float get();
};

float RotatePJoint::get()
{
    return m_value[52];
}
