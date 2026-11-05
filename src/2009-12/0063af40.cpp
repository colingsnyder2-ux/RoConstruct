// from server: 93% by atomic.potato
struct RunService
{
    void f(int value);
    void g();
};

void RunService::f(int value)
{
    if (value != 0)
        g();
}
