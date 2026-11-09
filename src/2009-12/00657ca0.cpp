// from server: 60% by atomic.potato
struct PartInstance
{
    PartInstance(int);
};

extern "C" void InitializePartInstance(PartInstance *, int);

PartInstance::PartInstance(int value)
{
    InitializePartInstance(this, value);
}
