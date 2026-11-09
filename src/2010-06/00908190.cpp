// from server: 41% by atomic.potato
struct RbxCluster {
    double f();
};

double RbxCluster::f()
{
    float value = *(float *)((char *)this + 0x290);
    if (value < 0.0f)
        return 0.0f;
    return value * value;
}
