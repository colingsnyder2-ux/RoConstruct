// from server: 72% by atomic.potato
struct RotatePJoint
{
    char padding[0xd4];
    int field_d4;
    float field_d8;
    void Update();
};

extern "C" void __cdecl Function_0074b490(int, float);

void RotatePJoint::Update()
{
    if (field_d4)
        Function_0074b490(field_d4, field_d8);
}
