// from server: 66% by atomic.potato
extern "C" void __stdcall CallTarget(void *, void *, double);

double g_value;

struct PingJob
{
    PingJob();
};

PingJob::PingJob()
{
    CallTarget(this, *(void **)((char *)this + 4), g_value);
}
