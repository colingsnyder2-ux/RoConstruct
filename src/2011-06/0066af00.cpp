// from server: 50% by atomic.potato
struct Profiler
{
    double value;
    int pad[2];
    int count;
    double f();
};

double Profiler::f()
{
    if (value > 0.0)
        return (double)count / value;
    return value;
}
