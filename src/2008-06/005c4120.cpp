// from server: 100% by king_originala
extern int profilingEnabled;

struct Sample
{
    double elapsed;
    double value;
    unsigned int count;
};

struct Profiler
{
    char padding[8];
    double interval;
    unsigned int position;
    Sample samples[2048];

    Sample accumulate(double duration);
};

Sample Profiler::accumulate(double duration)
{
    Sample result = { 0.0, 0.0, 0 };

    if (profilingEnabled)
    {
        unsigned int start = position + 2047;
        unsigned int maximum = 2046;
        int minimum = 1;
        int requested = (int)(duration / interval);
        const int& lowerBound = requested < minimum ? minimum : requested;
        unsigned int bounded = lowerBound;
        const unsigned int& upperBound =
            bounded > maximum ? maximum : bounded;
        unsigned int limit = upperBound;

        for (unsigned int i = 0; i < limit; ++i)
        {
            const Sample& sample = samples[(start - i) & 2047];
            result.elapsed += sample.elapsed;
            result.value += sample.value;
            result.count += sample.count;
            if (result.elapsed >= duration)
                break;
        }
    }

    return result;
}
