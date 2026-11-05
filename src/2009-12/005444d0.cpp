// from server: 66% by atomic.potato
extern "C" void __stdcall sub_7e7f30(void *, void *, double);

struct PingJob
{
    PingJob *f(void *, void *);
};

PingJob *PingJob::f(void *a, void *b)
{
    static const double value = 0.0;
    sub_7e7f30(b, a, value);
    return this;
}
