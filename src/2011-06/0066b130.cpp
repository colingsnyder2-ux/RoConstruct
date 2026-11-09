// from server: 100% by atomic.potato
struct Profiler
{
    int unused;
    int* begin;
    int* end;
    int unused2;
    int unused3;
    int field14;
    void f();
};

void Profiler::f()
{
    int* p = begin;
    while (p != end)
    {
        *p = 0;
        ++p;
    }
    field14 = 0;
}
