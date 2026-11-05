// from server: 82% by atomic.potato
struct InterpolatingPhysicsReceiver_Job
{
    double m_value;
    char pad0[544];
    double m_field228;
    int f(int a1, int a2);
};

extern "C" int __stdcall Function_00977d20(double value, int a1, int a2);

int InterpolatingPhysicsReceiver_Job::f(int a1, int a2)
{
    Function_00977d20(m_field228, a1, a2);
    return a1;
}
