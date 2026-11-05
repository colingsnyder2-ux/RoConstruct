// from server: 100% by atomic.potato
struct RotateConnector
{
    int getValue(int flag);
};

int RotateConnector::getValue(int flag)
{
    if (flag == 0)
        return *reinterpret_cast<int *>(*reinterpret_cast<int **>(
            reinterpret_cast<char *>(this) + 0x14) + 3);

    return *reinterpret_cast<int *>(*reinterpret_cast<int **>(
        reinterpret_cast<char *>(this) + 0x18) + 3);
}
