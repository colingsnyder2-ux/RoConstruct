// from server: 72% by atomic.potato
extern "C" void __cdecl sub_007AAB90(int, float);

struct RotatePJoint
{
    char pad[0xd4];
    int field_D4;
    float field_D8;
    void f();
};

void RotatePJoint::f()
{
    if (field_D4)
        sub_007AAB90(field_D4, field_D8);
}
