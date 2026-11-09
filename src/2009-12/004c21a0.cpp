// from server: 47% by atomic.potato
struct RbxCluster
{
    float getValue(float);
};

float RbxCluster::getValue(float)
{
    float value = *(float*)((char*)this + 0x290);
    return value < 0.0f ? 0.0f : value * value;
}
