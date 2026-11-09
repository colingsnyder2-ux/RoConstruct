// from server: 100% by atomic.potato
struct EdgeEdgeConnector
{
    char padding68[0x68];
    int field68;
    char padding84[0x18];
    int field84;
    int connect(int value);
};

extern "C" void __cdecl sub_7c77c0(EdgeEdgeConnector *);

int EdgeEdgeConnector::connect(int value)
{
    field84 = 0xa7fbbc;
    field68 = 0xa7fbbc;
    if (value & 1)
        sub_7c77c0(this);
    return (int)this;
}
