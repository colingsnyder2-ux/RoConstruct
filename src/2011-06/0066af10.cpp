// from server: 57% by atomic.potato
struct Profiler
{
    double getValue();
    int count;
    double elapsed;
};

double Profiler::getValue()
{
    if (elapsed >= 0.0)
        return (double)count / elapsed;
    return 0.0;
}
