// from server: 77% by atomic.potato
extern "C" void __stdcall Function_007e7f30(double, int, int);

double Global_009b9d90;

struct StatsUpdateJob
{
    StatsUpdateJob *Update(int, int);
};

StatsUpdateJob *StatsUpdateJob::Update(int a, int b)
{
    Function_007e7f30(Global_009b9d90, a, b);
    return this;
}
