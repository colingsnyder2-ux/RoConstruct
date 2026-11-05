// from server: 100% by atomic.potato
struct seg_00890000
{
    unsigned int capacity;
    unsigned int index;
    char pad8[4];
    double* values;

    void f(double value, unsigned char advance);
};

void seg_00890000::f(double value, unsigned char advance)
{
    values[index] = value;
    if (advance)
    {
        ++index;
        index %= capacity;
    }
}
