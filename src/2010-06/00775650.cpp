// from server: 89% by atomic.potato
struct EquationDisplay
{
    int value0;
    int value1;
    int value2;
    unsigned int f(int) const;
};

unsigned int EquationDisplay::f(int shift) const
{
    unsigned int value = (unsigned int)value2 * 0x04F9FFB7u;
    value ^= (unsigned int)value1 * 0x0127409Fu;
    value ^= (unsigned int)value0 * 0x0466F45Du;
    return value & (0xFFFFu >> shift);
}
