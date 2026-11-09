// from server: 100% by atomic.potato
extern "C" int __stdcall func_006f7880(int divisor, int dividend)
{
    int quotient = dividend / divisor;
    int remainder = dividend % divisor;
    return quotient + (remainder != 0);
}
