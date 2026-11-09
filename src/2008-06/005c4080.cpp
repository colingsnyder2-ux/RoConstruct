// from server: 100% by king_originala
extern "C" double __cdecl clockNow();

struct Profiler
{
    struct Bucket
    {
        double elapsed;
        double value;
        int count;
    };

    char reserved[8];
    double interval;
    unsigned int current;
    char padding[4];
    Bucket buckets[2048];
    double lastTime;

    void sample(bool counted, double value);
};

void Profiler::sample(bool counted, double value)
{
    double now = clockNow();
    double elapsed = now - lastTime;

    if (elapsed >= interval)
    {
        current = (current + 1) & 0x7ff;
        buckets[current].count = counted ? 1 : 0;
        buckets[current].elapsed = elapsed;
        buckets[current].value = value;
    }
    else
    {
        if (counted)
            ++buckets[current].count;
        buckets[current].elapsed += elapsed;
        buckets[current].value += value;
    }

    lastTime = now;
}
