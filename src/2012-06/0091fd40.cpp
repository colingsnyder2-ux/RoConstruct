// from server: 72% by atomic.potato
extern "C" void __cdecl Function008ff8d0(int, float);

struct RotateVJoint
{
    char paddingD0[208];
    int fieldD0;
    float fieldD4;
    void f();
};

void RotateVJoint::f()
{
    if (fieldD0)
        Function008ff8d0(fieldD0, fieldD4);
}
