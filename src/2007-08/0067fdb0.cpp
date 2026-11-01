// from server: 100% by colin
int __stdcall sub_0067FDB0(int divisor, int value)
{
    int quotient = value / divisor;
    int remainder = value % divisor;
    return quotient + (remainder != 0 ? 1 : 0);
}
