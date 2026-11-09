// from server: 100% by king_originala
struct Base
{
    virtual void virtualFunction();
    char storage[0xc03c];

    Base(const char*);
};

struct Profiler : Base
{
    int count;

    virtual void virtualFunction();
    Profiler(const char*);
};

Profiler::Profiler(const char* name)
    : Base(name), count(0)
{
}
