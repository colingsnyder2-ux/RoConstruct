// from server: 85% by atomic.potato
struct S
{
    float f();
    unsigned char padding[0x94];
    unsigned char initialized;
    unsigned char padding2[3];
    float value;
};

void S_init(S *);

float S::f()
{
    if (!initialized)
        S_init(this);
    return value;
}
