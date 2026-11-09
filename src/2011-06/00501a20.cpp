// from server: 100% by atomic.potato
extern "C" void* __stdcall sub_7FDD_B0(void*, void*, double);

struct PingJob {
    void* run(void* a, void* b);
};

void* PingJob::run(void* a, void* b)
{
    double d = *(double*)0x00A71028;
    sub_7FDD_B0(a, b, d);
    return a;
}
