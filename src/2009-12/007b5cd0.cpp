// from server: 91% by atomic.potato
extern "C" int __cdecl sub_773a90();

struct RotatePJoint
{
    char pad0[32];
    int value0;
    int value1;
    int f(int);
    int sub_7b5c70(int);
};

int RotatePJoint::f(int value)
{
    sub_773a90();
    value0 = 0x9ee09c;
    value1 = 0x9ee07c;
    sub_7b5c70(value);
    return (int)this;
}
