// from server: 73% by atomic.potato
extern "C" void __stdcall func_007d79a0(int, int);

struct MovingAssemblyStage
{
    int field0;
    int field4;
    int field8;
    float fieldc;
    MovingAssemblyStage* construct(int, int);
};

MovingAssemblyStage* MovingAssemblyStage::construct(int a, int b)
{
    func_007d79a0(a, b);
    float f = *(float*)0x9b477c;
    field0 = 0x9edd08;
    field4 = 0x9edd00;
    fieldc = f;
    return this;
}
