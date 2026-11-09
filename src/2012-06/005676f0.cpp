// from server: 100% by atomic.potato
struct S
{
    unsigned int reserved0;
    unsigned int reserved1;
    unsigned int index;
    unsigned char* bits;

    unsigned char f();
};

unsigned char S::f()
{
    unsigned int value = index;
    unsigned char result = (bits[value >> 3] & (unsigned char)(0x80 >> (value & 7))) != 0;
    index = value + 1;
    return result;
}
