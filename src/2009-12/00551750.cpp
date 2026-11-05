// from server: 23% by atomic.potato
struct PacketReceiveJob
{
    struct State
    {
        char padding[0x110];
        double value;
    };

    State* getState();
    int process(int, int);
};

PacketReceiveJob::State* PacketReceiveJob::getState()
{
    return 0;
}

int PacketReceiveJob::process(int value, int amount)
{
    State* state = getState();
    return value;
}
