// from server: 58% by atomic.potato
extern "C" void sub_590150(void *, void *);

struct PBBBuilder
{
    char pad[0x28];
    float value0;
    float value1;

    PBBBuilder(void *);
};

float g_9af2fc;

PBBBuilder::PBBBuilder(void *arg)
{
    sub_590150(this, arg);
    value0 = 0.0f;
    value1 = *((float *)((char *)arg + 0x10)) * g_9af2fc;
}
