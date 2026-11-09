// from server: 58% by atomic.potato
extern "C" void sub_005e5750(void *, void *);

struct CornerWedgeBuilder
{
    char pad[0x28];
    float value28;
    float value2c;

    CornerWedgeBuilder(void *);
};

float g_value;

CornerWedgeBuilder::CornerWedgeBuilder(void *arg)
{
    sub_005e5750(this, arg);
    value28 = 0.0f;
    value2c = *(float *)((char *)arg + 0x10) * g_value;
}
