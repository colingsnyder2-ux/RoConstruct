// from server: 40% by atomic.potato
struct RotatePJoint
{
    void f();
};

void RotatePJoint::f()
{
    if (*(void**)((char*)this + 0xd0))
        f();
}
