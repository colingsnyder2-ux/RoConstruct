// from server: 74% by atomic.potato
struct P8NetworkSettings
{
    int pad0[4];
    int offset;
    int (*callback)(int, double);

    int GetSetImpl(void *p, const double *value);
};

int P8NetworkSettings::GetSetImpl(void *p, const double *value)
{
    int base;
    if (p)
        base = (char *)p - (char *)0 - 28;
    else
        base = 0;

    return callback(base + offset, *value);
}
