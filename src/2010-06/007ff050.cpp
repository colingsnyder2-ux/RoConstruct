// from server: 100% by atomic.potato
extern "C" int __stdcall func_007ff050(int divisor, int dividend)
{
    int quotient = dividend / divisor;
    int remainder = dividend % divisor;
    quotient += remainder != 0;
    return quotient;
}
