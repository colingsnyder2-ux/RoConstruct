// from server: 50% by atomic.potato
struct GeoPairConnector
{
    int Get(int);
};

int GeoPairConnector::Get(int value)
{
    value = *(int *)((char *)this + 8) - 3;
    if (value == 0)
        return 0;
    value -= 1;
    if (value == 0)
        return 0;
    value -= 1;
    if (value != 0)
        return 0;
    return 0;
}
