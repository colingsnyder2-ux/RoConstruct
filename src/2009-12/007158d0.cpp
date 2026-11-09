// from server: 60% by atomic.potato
extern "C" int sub_007b1ec0(int, int);

struct RotatePJoint
{
    char pad0[180];
    int body;
    int f();
};

int RotatePJoint::f()
{
    return sub_007b1ec0(body + 208, 3);
}
