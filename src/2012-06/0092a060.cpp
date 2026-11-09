// from server: 29% by atomic.potato
struct EdgeEdgePair
{
    int f();
};

int EdgeEdgePair::f()
{
    return (reinterpret_cast<int *>(this)[2] -
            reinterpret_cast<int *>(this)[1]) / 20;
}
