// from server: 46% by atomic.potato
struct S
{
    double value() const;
};

double S::value() const
{
    return *(const double *)((const char *)this + 0x1b0) * *(const double *)0x9b2e18;
}
