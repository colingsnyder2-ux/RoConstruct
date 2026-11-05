// from server: 100% by king_originala
struct Profiler
{
    virtual void virtualFunction();
    char storage[0xc03c];

    Profiler(const char*);
};

struct DerivedProfiler : Profiler
{
    virtual void virtualFunction();
    int count;

    DerivedProfiler(const char*);
};

DerivedProfiler::DerivedProfiler(const char* name)
    : Profiler(name), count(0)
{
}
