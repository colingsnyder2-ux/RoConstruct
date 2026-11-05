// from server: 53% by atomic.potato
struct GeoPairConnector
{
    int padding;
    int padding2;
    int value;
    int f(int);
};

int GeoPairConnector::f(int)
{
    switch (value - 3)
    {
    case 0:
        return 0;
    case 1:
        return 0;
    case 2:
        return 0;
    default:
        return 0;
    }
}
