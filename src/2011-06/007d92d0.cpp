// from server: 68% by atomic.potato
struct EquationDisplay {
    char pad[8];
    unsigned char shift;
    char pad2[8];
    int base;
    int __cdecl get(int lo, int hi);
};

int EquationDisplay::get(int lo, int hi)
{
    double d = *(double*)&lo;
    if (d == 0.0)
        return base;
    unsigned int divisor = (1u << shift) - 1u;
    divisor |= 1u;
    unsigned int sum = (unsigned int)lo + (unsigned int)hi;
    unsigned int rem = sum % divisor;
    return base + (int)(rem << 5);
}
