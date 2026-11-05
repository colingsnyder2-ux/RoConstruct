// from server: 53% by atomic.potato
struct S
{
    char padding0[0x2c];
    float value;
    char padding1[0x90 - 0x30];
    char input[0x1c];
    unsigned char flag;

    S* f();
};

extern "C" void BinaryInputInit(void*);

S* S::f()
{
    unsigned char b = 0;
    BinaryInputInit(input);
    value = 0.0f;
    flag = b;
    return this;
}
