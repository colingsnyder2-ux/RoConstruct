// from server: 94% by atomic.potato
struct HeartbeatTask
{
    char padding[0x1e0];
    double value;
    int f(int, int);
};

extern "C" int __stdcall heartbeat_call(int, int, double);

int HeartbeatTask::f(int a, int b)
{
    heartbeat_call(b, a, value);
    return b;
}
