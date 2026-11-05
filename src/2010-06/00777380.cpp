// from server: 35% by atomic.potato
extern "C" void CopyVector3(float *destination, const float *source);

struct EdgeEdgePair
{
    float data[3];
    EdgeEdgePair &f(int index, const float *source);
};

EdgeEdgePair &EdgeEdgePair::f(int index, const float *source)
{
    CopyVector3(data + index * 3, source);
    return *this;
}
