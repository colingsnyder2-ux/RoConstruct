// from server: 73% by atomic.potato
extern "C" void __stdcall sub_00983ba0(void *, void *);

struct TorsoBuilder
{
    int pad[10];
    TorsoBuilder *f(void *);
};

TorsoBuilder *TorsoBuilder::f(void *arg)
{
    sub_00983ba0(this, arg);
    *(float *)((char *)this + 40) = 0.0f;
    return this;
}
