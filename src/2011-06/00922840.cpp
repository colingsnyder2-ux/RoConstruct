// from server: 52% by atomic.potato
struct S
{
    unsigned char data[0x9c + 36];
    void f(const unsigned char *source);
};

void S::f(const unsigned char *source)
{
    unsigned char *destination = data + 0x9c;
    int i;
    for (i = 0; i != 9; ++i)
        ((unsigned long *)destination)[i] =
            ((const unsigned long *)source)[i];
    *(float *)(destination + 0x24) = *(const float *)(source + 0x24);
    *(float *)(destination + 0x28) = *(const float *)(source + 0x28);
    *(float *)(destination + 0x2c) = *(const float *)(source + 0x2c);
}
