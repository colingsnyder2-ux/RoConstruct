// from server: 18% by atomic.potato
struct BallBlockConnector
{
    void get();
};

void BallBlockConnector::get()
{
    int state = *(volatile int *)((char *)this + 0x74);

    if (state == 2)
        return;
    if (state == 1)
        return;
    return;
}
