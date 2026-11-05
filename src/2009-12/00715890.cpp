// from server: 66% by atomic.potato
extern "C" int __fastcall sub_007b1ec0(int, int);

struct RotatePJoint
{
    char pad0[180];
    int m_body;
    int f();
};

int RotatePJoint::f()
{
    return sub_007b1ec0(m_body + 208, 1);
}
