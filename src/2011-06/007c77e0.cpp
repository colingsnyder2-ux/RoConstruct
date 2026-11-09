// from server: 87% by atomic.potato
struct FaceVertexConnector
{
    char padding[0x68];
    int value;
    FaceVertexConnector* reset(int);
};

FaceVertexConnector* FaceVertexConnector::reset(int flag)
{
    value = 0xA7FBC4;
    if (flag & 1)
        reset(0);
    return this;
}
