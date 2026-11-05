// from server: 76% by atomic.potato
struct Log
{
    char padding[184];
    double value;

    static int compare(const Log *, const Log *);
};

int Log::compare(const Log *a, const Log *b)
{
    return a->value > b->value ? 1 : 0;
}
