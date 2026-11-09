// from server: 31% by atomic.potato
extern "C" void __stdcall func_00701750(int, int);
extern "C" void __stdcall func_00719c70(int, int, int);

struct MovingAssemblyStage
{
    char pad[0x1c];
    int field1c;
    void f(int);
};

void MovingAssemblyStage::f(int arg)
{
    int local;
    func_00701750((int)&local, arg);
    float f = *(float*)0x9e9790;
    func_00719c70((int)&field1c, (int)&local, *(int*)&f);
}
