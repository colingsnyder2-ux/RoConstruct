// from server: 100% by tester
struct S
{
    unsigned char padding[8];
    unsigned int value;
    unsigned char* bits;

    unsigned char f();
};

unsigned char S::f()
{
    unsigned int n = value;
    unsigned char result = (bits[n >> 3] & (unsigned char)(0x80 >> (n & 7))) != 0;
    value = n + 1;
    return result;
}
