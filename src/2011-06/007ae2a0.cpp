// from server: 72% by atomic.potato
struct RotateVJoint
{
    char padding[208];
    int fieldD0;
    float fieldD4;
    void f();
};

extern "C" void __cdecl Function0079b390(int, float);

void RotateVJoint::f()
{
    if (fieldD0)
        Function0079b390(fieldD0, fieldD4);
}
