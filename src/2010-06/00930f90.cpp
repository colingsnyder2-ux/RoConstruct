// from server: 78% by atomic.potato
extern "C" void __stdcall sub_928e60(void *);

struct TorsoBuilder {
    char padding[40];
    float field_28;
    TorsoBuilder *f(void *);
};

TorsoBuilder *TorsoBuilder::f(void *arg)
{
    sub_928e60(arg);
    field_28 = 0.0f;
    return this;
}
