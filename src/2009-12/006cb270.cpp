// from server: 82% by atomic.potato
struct Profiler
{
    char padding[0xe8];
    double value;
    int f();
};

extern "C" double __cdecl sub_7e5d40(double *);

int Profiler::f()
{
    double local = sub_7e5d40(&local);
    return value > local;
}
