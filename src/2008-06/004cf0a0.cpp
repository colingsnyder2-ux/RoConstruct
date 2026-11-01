// from server: 100% by atomic.potato
struct PhysicsSender
{
    unsigned int f();
};

unsigned int PhysicsSender::f()
{
    unsigned int a = *(unsigned int *)((char *)this + 4);
    unsigned int b = *(unsigned int *)((char *)this + 8);
    if (a <= b)
        return b - a;
    return *(unsigned int *)((char *)this + 12) - a + b;
}
