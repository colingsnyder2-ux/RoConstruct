// from server: 81% by atomic.potato
extern "C" void __stdcall Function_0079b610(void *, void *, double);

double g_00a179e8;

struct StatsUpdateJob
{
    void *Update(void *, void *);
};

void *StatsUpdateJob::Update(void *a, void *b)
{
    Function_0079b610(this, a, g_00a179e8);
    return a;
}
