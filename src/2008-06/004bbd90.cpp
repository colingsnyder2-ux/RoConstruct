// from server: 100% by colin
struct ProfiledRakPeer
{
    char padding[0x6d4];
    unsigned int denominator;
    unsigned int unused;
    unsigned int numerator;
    double getAverage();
};
double ProfiledRakPeer::getAverage()
{
    if (denominator > 0) return (float)numerator / (float)denominator; return 0.0;
}
