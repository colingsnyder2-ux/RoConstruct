// from server: 100% by atomic.potato
struct PhysicsSender
{
    void f(double value, int first, int second);
};

void PhysicsSender::f(double value, int first, int second)
{
    *(double*)((char*)this + 0x7a0) = value;
    *(int*)((char*)this + 0x7a8) = first;
    *(int*)((char*)this + 0x7ac) = second;
}
