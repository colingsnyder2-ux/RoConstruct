// from server: 100% by atomic.potato
struct RotateConnector
{
    int *Get(int);
};

int *RotateConnector::Get(int value)
{
    if (value == 0)
        return *(int **)((char *)this + 8);
    return *(int **)((char *)this + 12);
}
