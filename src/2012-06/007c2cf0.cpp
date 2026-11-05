// from server: 42% by atomic.potato
struct S
{
    float f();
};

volatile unsigned char gFlag = 0;
volatile float gValue = 0.0f;

float S::f()
{
    float result;

    if (gFlag)
    {
        result = gValue;
    }
    else
    {
        result = *(float *)((*(unsigned int *)((char *)this + 0x84)) + 0x84);
    }

    return result;
}
