// from server: 59% by atomic.potato
struct RunService
{
    void f(int value);
};

void RunService::f(int value)
{
    if (value != 0)
        f(value);
}
