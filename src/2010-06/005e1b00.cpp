// from server: 42% by atomic.potato
struct ClearBackpack
{
    void *field50;
    int f();
};

int ClearBackpack::f()
{
    struct Range
    {
        int begin;
        int end;
    };

    Range *range = (Range *)field50;
    int count = 0;

    if (range != 0)
        count = (range->end - range->begin) >> 3;

    return count != 0;
}
