// from server: 64% by atomic.potato
struct JobInterface
{
    virtual int Check(int value) = 0;
};

struct Job
{
    unsigned char pad[4];
    unsigned char enabled;
    unsigned char pad2[3];
    JobInterface *receiver;
    int f(int *value);
};

int Job::f(int *value)
{
    if (enabled)
    {
        if (!receiver->Check(*value))
            return 0;
    }

    return 1;
}
