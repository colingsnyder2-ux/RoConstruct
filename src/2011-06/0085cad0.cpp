// from server: 100% by atomic.potato
int __stdcall func_0085cad0(int divisor, int dividend)
{
    int quotient = dividend / divisor;
    int remainder = dividend % divisor;
    return quotient + (remainder != 0);
}
