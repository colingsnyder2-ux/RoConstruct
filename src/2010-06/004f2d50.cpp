// from server: 84% by atomic.potato
extern "C" void __stdcall CallTarget(void*, void*, double);

double GlobalValue = 0.0;

struct PingJob
{
    PingJob* f(void*, void*);
};

PingJob* PingJob::f(void* a, void* b)
{
    CallTarget(this, b, GlobalValue);
    return this;
}
