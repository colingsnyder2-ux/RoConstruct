// from server: 63% by atomic.potato
extern "C" void sub_928e60(void *);

struct HeadBuilder
{
    char data[0x30];
    HeadBuilder *f(void *);
};

HeadBuilder *HeadBuilder::f(void *arg)
{
    sub_928e60(arg);
    *(float *)(data + 0x28) = 0.0f;
    *(float *)(data + 0x2c) = *(float *)((char *)arg + 0x10) * 0.001f;
    return this;
}
