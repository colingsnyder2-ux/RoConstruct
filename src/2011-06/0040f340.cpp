// from server: 100% by atomic.potato
struct VFunctions
{
    void f();
    void next();
};

void VFunctions::f()
{
    *(int*)this = 0xA5C784;
    *((int*)this + 1) = 0xA5C778;
    *((int*)this + 6) = 0xA5C76C;
    *((int*)this + 7) = 0xA5C760;
    next();
}
