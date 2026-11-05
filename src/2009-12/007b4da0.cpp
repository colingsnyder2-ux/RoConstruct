// from server: 62% by atomic.potato
extern "C" void __cdecl Call007AAC10(float);

struct RotateVJoint
{
    char paddingD4[212];
    int fieldD4;
    float fieldD8;
    void f();
};

void RotateVJoint::f()
{
    if (fieldD4)
        Call007AAC10(fieldD8);
}
