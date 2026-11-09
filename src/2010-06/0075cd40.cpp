// from server: 72% by atomic.potato
extern "C" void __cdecl sub_74B510(int, float);

struct RotateVJoint
{
    int pad[53];
    int fieldD4;
    float fieldD8;

    void f();
};

void RotateVJoint::f()
{
    if (fieldD4)
        sub_74B510(fieldD4, fieldD8);
}
