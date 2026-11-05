// from server: 81% by atomic.potato
struct StatsUpdateJob
{
    int f(int a, int b);
};

extern "C" void __cdecl Update(double value, int a, int b);

double g_value = 0.0;

int StatsUpdateJob::f(int a, int b)
{
    Update(g_value, a, b);
    return b;
}
