// from server: 100% by atomic.potato
int __stdcall func_0084b020(int divisor, int dividend)
{
    int quotient = dividend / divisor;
    quotient += dividend % divisor != 0;
    return quotient;
}
