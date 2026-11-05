// from server: 100% by atomic.potato
struct KernelJoint
{
    int m_values[1];
    int get(int index);
};

int KernelJoint::get(int index)
{
    int value = m_values[index - 4];
    return value ? value + 8 : 0;
}
