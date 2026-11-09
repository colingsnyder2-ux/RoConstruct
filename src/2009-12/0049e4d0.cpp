// from server: 100% by atomic.potato
struct RbxMeshPartAdapter
{
    float data[17];
    RbxMeshPartAdapter& copy(const float* src);
};

RbxMeshPartAdapter& RbxMeshPartAdapter::copy(const float* src)
{
    data[0] = src[0];
    data[1] = src[1];
    data[2] = src[2];
    data[3] = src[3];
    data[4] = src[4];
    data[5] = src[5];
    data[6] = src[6];
    data[7] = src[7];
    data[8] = src[8];
    data[9] = src[9];
    data[10] = src[10];
    data[11] = src[11];
    data[12] = src[12];
    data[13] = src[13];
    data[14] = src[14];
    data[15] = src[15];
    data[16] = src[16];
    return *this;
}
