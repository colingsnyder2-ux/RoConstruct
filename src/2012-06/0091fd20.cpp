// from server: 38% by atomic.potato
extern "C" void __cdecl CallTarget(float);

struct RotatePJoint
{
    int fieldD0;
    float fieldD4;
    void f();
};

void RotatePJoint::f()
{
    if (fieldD0)
        CallTarget(fieldD4);
}
