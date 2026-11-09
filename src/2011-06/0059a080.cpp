// from server: 7% by atomic.potato
struct HeartbeatTask
{
    int operator()();
};

int HeartbeatTask::operator()()
{
    return 0;
}
