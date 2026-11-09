// from server: 71% by atomic.potato
struct S
{
    char pad[8];
    double value;
    int count;
    double get() const;
};

double S::get() const
{
    if (value > 0.0)
        return (double)count / value;
    return 0.0;
}
