// from server: 73% by atomic.potato
struct RotateSelectionVerb
{
    int f(int);
};

extern "C" void __cdecl Geometry_ctor();
extern "C" void Sphere_copy(void *, const void *);

int RotateSelectionVerb::f(int value)
{
    Geometry_ctor();
    Sphere_copy((void *)value, this);
    return (int)this;
}
