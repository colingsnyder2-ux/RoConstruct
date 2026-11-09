// from server: 51% by atomic.potato
struct RakPeer
{
    char padding[0xa98];
    double value;
    unsigned short flag1;
    unsigned short flag2;

    int getStatus();
};

int RakPeer::getStatus()
{
    if (value > 0.0)
        return 1;
    if (flag1 > 0)
        return 1;
    if (flag2 > 0)
        return 1;
    return 0;
}
