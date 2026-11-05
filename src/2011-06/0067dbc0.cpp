// from server: 90% by atomic.potato
struct KernelJoint
{
    int m_values[110];
    void get(int* result);
};

void KernelJoint::get(int* result)
{
    result[0] = m_values[110];
    result[1] = m_values[111];
    result[2] = m_values[112];
}
