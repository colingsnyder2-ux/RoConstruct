// from server: 100% by atomic.potato
struct PointToPointBreakConnector
{
    int get(int value);
};

int PointToPointBreakConnector::get(int value)
{
    if (value == 0)
        return *reinterpret_cast<int *>(*reinterpret_cast<int *>(reinterpret_cast<char *>(this) + 8) + 12);

    return *reinterpret_cast<int *>(*reinterpret_cast<int *>(reinterpret_cast<char *>(this) + 12) + 12);
}
