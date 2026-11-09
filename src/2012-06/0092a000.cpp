// from server: 55% by atomic.potato
struct PolyPair
{
    unsigned int value0;
    unsigned int value1;
    unsigned int value2;
    unsigned int value3;
    unsigned int value4;
    unsigned int value5;
    void f(const unsigned int* source);
};

void PolyPair::f(const unsigned int* source)
{
    value0 = 0x00bfdb74;
    value1 = source[1];
    value2 = source[2];
    value3 = source[3];
    value4 = source[4];
    value5 = source[5];
}
