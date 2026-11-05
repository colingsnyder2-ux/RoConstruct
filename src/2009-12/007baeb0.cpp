// from server: 100% by atomic.potato
extern "C" void __cdecl func_005ea3e0(int);

struct MovingAssemblyStage
{
    int padding18[6];
    int field18;
    int field1c;
    int field20;
    int f();
};

int MovingAssemblyStage::f()
{
    func_005ea3e0(field18);
    field18 = 0;
    field1c = 0;
    field20 = 0;
    return 0;
}
