// from server: 82% by atomic.potato
typedef double Double;

extern "C" void __stdcall Function_009779e0(Double value, int a0, int a1);

struct InterpolatingPhysicsReceiver_Job
{
    char pad0[0x228];
    Double value;
    int f(int a0, int a1);
};

int InterpolatingPhysicsReceiver_Job::f(int a0, int a1)
{
    Function_009779e0(value, a0, a1);
    return a0;
}
