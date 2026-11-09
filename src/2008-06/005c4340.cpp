// from server: 100% by king_originala
extern const double initialValue;
extern double __cdecl currentTime();

typedef void* (__thiscall *StringConstructor)(void*, const char*);
extern StringConstructor constructString;

struct Sample {
    double first;
    double second;
    int count;
};

struct Profiler {
    virtual void virtualFunction();
    double value;
    int count;
    Sample samples[2048];
    double startTime;
    char name[28];

    Profiler(const char*);
};

Profiler::Profiler(const char* text)
{
    value = initialValue;
    count = 0;

    Sample* sample = samples;
    int remaining = 2047;
    do {
        sample->first = 0.0;
        sample->count = 0;
        sample->second = 0.0;
        ++sample;
    } while (--remaining >= 0);

    startTime = currentTime();
    constructString(name, text);
}
