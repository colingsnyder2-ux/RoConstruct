// from server: 100% by atomic.potato
extern "C" void __stdcall G1_func_007420b0(int, int);

struct VelocityMotor
{
    char padding[184];
    int value;
    void f();
};

void VelocityMotor::f()
{
    G1_func_007420b0(1, value);
}
