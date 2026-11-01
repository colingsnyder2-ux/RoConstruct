// from server: 83% by atomic.potato
struct ContactStage
{
    int value;
    int stage;
    void f(int);
};

extern "C" void __stdcall func_007b9990(int, int);
extern "C" void __stdcall func_007b2f40(int, int);

void ContactStage::f(int value)
{
    func_007b9990(stage, value);
    func_007b2f40(value, (int)this);
}
