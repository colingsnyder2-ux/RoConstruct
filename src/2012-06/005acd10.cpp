// from server: 100% by tajop
struct S
{
    double value;
    unsigned char state;
};

struct Job
{
    char pad[0x228];
    float rate;
    bool canSend();
    S compute(const S& stats, double hz);
    S sleepTime(const S& stats);
};

S Job::sleepTime(const S& stats)
{
    if (canSend())
        return compute(stats, rate);
    S r;
    r.value = 0.0;
    r.state = 0;
    return r;
}
