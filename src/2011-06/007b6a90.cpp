// from server: 49% by atomic.potato
extern "C" void __stdcall func_007b6960(int);
extern "C" void __stdcall func_007b66f0();

struct MovingAssemblyStage
{
    int state;
    int pad[3];
    int value;
    void f();
};

void MovingAssemblyStage::f()
{
    int value = this->value;
    if (value == 0 || value == 2)
        func_007b6960(1);
    else if (value == 1)
        func_007b6960(3);
    else
        func_007b66f0();
}
