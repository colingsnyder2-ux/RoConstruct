// from server: 100% by atomic.potato
struct RotateConnector
{
    int get(int value);
};

int RotateConnector::get(int value)
{
    if (value == 0)
        return *(int*)((char*)this + 8);
    return *(int*)((char*)this + 12);
}
